#include <tree_sitter/parser.h>
#include <stdbool.h>

void *tree_sitter_teal_external_scanner_create() { return NULL; }
void tree_sitter_teal_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_teal_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_teal_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}
static inline void consume(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

#define ACTION_WHILE(action) \
    static inline unsigned int action ## _while (bool (*fn)(TSLexer*), TSLexer *lexer) { \
        unsigned int n = 0; \
        while (fn(lexer)) { action(lexer); ++n; } \
        return n; }
ACTION_WHILE(consume)
ACTION_WHILE(skip)

#define PREDICATE_ANY_OF(name, cases) \
    static inline bool name (TSLexer *lexer) { switch (lexer->lookahead) { \
        cases return true; \
        default: return false; } }

#define PREDICATE_NONE_OF(name, cases) \
    static inline bool name (TSLexer *lexer) { switch (lexer->lookahead) { \
        cases return false; \
        default: return true; } }

#define C(x) case x :
PREDICATE_NONE_OF (not_nl_or_eof,      C(0) C('\n'))
PREDICATE_NONE_OF (not_right_bracket,  C(']'))
PREDICATE_ANY_OF  (is_whitespace,      C(' ') C('\n') C('\r') C('\t'))
PREDICATE_ANY_OF  (is_eq,              C('='))

enum TokenType {
    COMMENT,
    LONG_STRING,
};

#define RET_FALSE_IF_NOT(char) if (lexer->lookahead != char) return false; consume(lexer)

static bool scan_bracketed_content(TSLexer *lexer) {
    RET_FALSE_IF_NOT('[');
    const unsigned int start_eq = consume_while(is_eq, lexer);
    RET_FALSE_IF_NOT('[');

    while (lexer->lookahead != 0) {
        consume_while(not_right_bracket, lexer);
        RET_FALSE_IF_NOT(']');

        const unsigned int test_eq = consume_while(is_eq, lexer);
        RET_FALSE_IF_NOT(']');

        if (test_eq == start_eq) return true;
    }

    return false;
}

bool tree_sitter_teal_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    skip_while(is_whitespace, lexer);

    if (valid_symbols[COMMENT]) {
        RET_FALSE_IF_NOT('-');
        RET_FALSE_IF_NOT('-');
        lexer->result_symbol = COMMENT;
        if (scan_bracketed_content(lexer)) return true;
        consume_while(not_nl_or_eof, lexer); return true;
    } else if (valid_symbols[LONG_STRING]) {
        if (scan_bracketed_content(lexer)) {
            lexer->result_symbol = LONG_STRING;
            return true;
        }
        return false;
    }

    return false;
}

