#include <tree_sitter/parser.h>
#include <stdbool.h>
#include <stdio.h>

void *tree_sitter_teal_external_scanner_create() { return NULL; }
void tree_sitter_teal_external_scanner_destroy(void *payload) {}

static inline void consume(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

enum TokenType {
    COMMENT,

    LONG_STRING_START,
    LONG_STRING_CHAR,
    LONG_STRING_END,

    SHORT_STRING_START,
    SHORT_STRING_CHAR,
    SHORT_STRING_END,
};

#define EXPECT(char) do { if (lexer->lookahead != char) { return false; } consume(lexer); } while (0)
#define CONSUME_EQS(n) do { while (lexer->lookahead == '=') { consume(lexer); ++ n ; } } while (0)
/* #define LOG() do { printf("%s '%c'\n", __FUNCTION__, lexer->lookahead == '\n' ? '~' : lexer->lookahead); } while (0) */
#define LOG()

static void consume_rest_of_line(TSLexer *lexer) {
    while (lexer->lookahead > 0) {
        switch (lexer->lookahead) {
            case '\n': case '\r': return;
            default: consume(lexer);
        }
    }
}

static bool scan_comment(TSLexer *lexer) {
    LOG();
    EXPECT('-'); EXPECT('-');
    lexer->result_symbol = COMMENT;

    if (lexer->lookahead != '[') {
        consume_rest_of_line(lexer);
        return true;
    }

    consume(lexer);
    uint8_t eqs = 0;
    CONSUME_EQS(eqs);

    if (lexer->lookahead != '[') {
        consume_rest_of_line(lexer);
        return true;
    }

    while (lexer->lookahead > 0) {
        while (lexer->lookahead > 0 && lexer->lookahead != ']')
            consume(lexer);

        EXPECT(']');
        uint8_t test_eq = 0;
        CONSUME_EQS(test_eq);
        if (lexer->lookahead == ']') {
            consume(lexer);
            if (test_eq == eqs) {
                return true;
            }
        } else if (lexer->lookahead != 0) {
            consume(lexer);
        }
    }

    return true;
}

// state
static uint8_t opening_eqs = 0;
static bool in_str = false;
static char opening_quote = 0;

static inline void reset_state() {
    opening_eqs = 0;
    in_str = false;
    opening_quote = 0;
}

unsigned tree_sitter_teal_external_scanner_serialize(void *payload, char *buffer) {
    buffer[0] = opening_eqs;
    buffer[1] = in_str;
    buffer[2] = opening_quote;
    return 3;
}

void tree_sitter_teal_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    if (length == 0) return;
    opening_eqs = buffer[0];
    if (length == 1) return;
    in_str = buffer[1];
    if (length == 2) return;
    opening_quote = buffer[2];
}

static bool scan_short_string_start(TSLexer *lexer) {
    LOG();
    if ((lexer->lookahead == '"') || (lexer->lookahead == '\'')) {
        opening_quote = lexer->lookahead;
        in_str = true;
        consume(lexer);
        lexer->result_symbol = SHORT_STRING_START;
        return true;
    }
    return false;
}

static bool scan_short_string_end(TSLexer *lexer) {
    LOG();
    if (in_str && lexer->lookahead == opening_quote) {
        consume(lexer);
        lexer->result_symbol = SHORT_STRING_END;
        reset_state();
        return true;
    }
    return false;
}

static bool scan_short_string_char(TSLexer *lexer) {
    LOG();
    if (
        in_str
        && opening_quote > 0
        && lexer->lookahead != opening_quote
        && lexer->lookahead != '\n'
        && lexer->lookahead != '\r'
        && lexer->lookahead != '\\'
        && lexer->lookahead != '%'
    ) {
        consume(lexer);
        lexer->result_symbol = SHORT_STRING_CHAR;
        return true;
    }
    return false;
}

static bool scan_long_string_start(TSLexer *lexer) {
    LOG();
    EXPECT('[');
    reset_state();
    uint8_t eqs = 0;
    CONSUME_EQS(eqs);
    EXPECT('[');
    in_str = true;
    lexer->result_symbol = LONG_STRING_START;
    opening_eqs = eqs;
    return true;
}

static bool scan_long_string_end(TSLexer *lexer) {
    LOG();
    EXPECT(']');

    uint8_t eqs = 0;
    CONSUME_EQS(eqs);
    if (opening_eqs == eqs && lexer->lookahead == ']') {
        consume(lexer);
        lexer->result_symbol = LONG_STRING_END;
        reset_state();
        return true;
    }
    return false;
}

bool scan_long_string_char(TSLexer *lexer) {
    if (lexer->lookahead == '%') {
        return false;
    }
    consume(lexer);
    lexer->result_symbol = LONG_STRING_CHAR;
    return true;
}

static inline bool is_whitespace(char c) {
    switch (c) {
        default: return false;
        case '\n': case '\r': case ' ': case '\t':
            return true;
    }
}

bool tree_sitter_teal_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    LOG();
    if (lexer->lookahead == 0)
        return false;

    if (in_str) {
        if (opening_quote > 0) {
            return (valid_symbols[SHORT_STRING_END] && scan_short_string_end(lexer))
                || (valid_symbols[SHORT_STRING_CHAR] && scan_short_string_char(lexer));
        } else {
            return scan_long_string_end(lexer)
                || scan_long_string_char(lexer);
        }
    } else {
        while (is_whitespace(lexer->lookahead))
            skip(lexer);

        if (valid_symbols[SHORT_STRING_START] && scan_short_string_start(lexer))
            return true;

        if (valid_symbols[LONG_STRING_START] && scan_long_string_start(lexer))
            return true;
    }

    while (is_whitespace(lexer->lookahead))
        skip(lexer);

    return valid_symbols[COMMENT] && scan_comment(lexer);
}

