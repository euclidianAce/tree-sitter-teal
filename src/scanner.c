#include <tree_sitter/parser.h>
#include <stdbool.h>
#include <stdio.h>

void *tree_sitter_teal_external_scanner_create() { return NULL; }
void tree_sitter_teal_external_scanner_destroy(void *payload) {}

static inline void consume(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

enum TokenType {
    LONG_COMMENT_CONTENT,

    LONG_STRING_START,
    LONG_STRING_CHAR,
    LONG_STRING_END,
};

#define EXPECT(char) if (lexer->lookahead != char) return false; consume(lexer)
#define CONSUME_EQS(n) do { while (lexer->lookahead == '=') { consume(lexer); ++ n ; } } while (0)

static bool scan_long_comment_content(TSLexer *lexer) {
    EXPECT('[');
    uint8_t eqs = 0;
    CONSUME_EQS(eqs);
    EXPECT('[');

    while (lexer->lookahead > 0) {
        lexer->result_symbol = LONG_COMMENT_CONTENT;
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

    return false;
}

// state
static uint8_t opening_eqs = 0;

static inline void reset_state() {
    opening_eqs = 0;
}

unsigned tree_sitter_teal_external_scanner_serialize(void *payload, char *buffer) {
    buffer[0] = opening_eqs;
    return 1;
}

void tree_sitter_teal_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    if (length == 0) return;
    opening_eqs = buffer[0];
}

static bool scan_long_string_start(TSLexer *lexer) {
    EXPECT('[');
    uint8_t eqs = 0;
    CONSUME_EQS(eqs);
    EXPECT('[');
    reset_state();
    lexer->result_symbol = LONG_STRING_START;
    opening_eqs = eqs;
    return true;
}

static bool scan_long_string_end(TSLexer *lexer) {
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
    if (lexer->lookahead == 0) return false;

#define IF_VALID_TRY_SCAN(symbol, func) \
    if (valid_symbols[ symbol ] && func (lexer)) return true

    IF_VALID_TRY_SCAN(LONG_STRING_END, scan_long_string_end);
    IF_VALID_TRY_SCAN(LONG_STRING_CHAR, scan_long_string_char);
    IF_VALID_TRY_SCAN(LONG_COMMENT_CONTENT, scan_long_comment_content);

    while (is_whitespace(lexer->lookahead)) skip(lexer);
    IF_VALID_TRY_SCAN(LONG_STRING_START, scan_long_string_start);

    reset_state();
    return false;
}

