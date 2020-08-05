#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 55
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 24
#define ALIAS_COUNT 0
#define TOKEN_COUNT 13
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6

enum {
  anon_sym_local = 1,
  anon_sym_COMMA = 2,
  anon_sym_EQ = 3,
  anon_sym_global = 4,
  anon_sym_LBRACE = 5,
  anon_sym_SEMI = 6,
  anon_sym_LBRACK = 7,
  anon_sym_RBRACK = 8,
  anon_sym_RBRACE = 9,
  sym_identifier = 10,
  sym_number = 11,
  sym_string = 12,
  sym_program = 13,
  sym__statement = 14,
  sym__expression = 15,
  sym_local_declaration = 16,
  sym_global_declaration = 17,
  sym_table_constructor = 18,
  aux_sym_program_repeat1 = 19,
  aux_sym_local_declaration_repeat1 = 20,
  aux_sym_local_declaration_repeat2 = 21,
  aux_sym_table_constructor_repeat1 = 22,
  aux_sym_table_constructor_repeat2 = 23,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_local] = "local",
  [anon_sym_COMMA] = ",",
  [anon_sym_EQ] = "=",
  [anon_sym_global] = "global",
  [anon_sym_LBRACE] = "{",
  [anon_sym_SEMI] = ";",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_RBRACE] = "}",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym_string] = "string",
  [sym_program] = "program",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym_local_declaration] = "local_declaration",
  [sym_global_declaration] = "global_declaration",
  [sym_table_constructor] = "table_constructor",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_local_declaration_repeat1] = "local_declaration_repeat1",
  [aux_sym_local_declaration_repeat2] = "local_declaration_repeat2",
  [aux_sym_table_constructor_repeat1] = "table_constructor_repeat1",
  [aux_sym_table_constructor_repeat2] = "table_constructor_repeat2",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_local] = anon_sym_local,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_global] = anon_sym_global,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_identifier] = sym_identifier,
  [sym_number] = sym_number,
  [sym_string] = sym_string,
  [sym_program] = sym_program,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym_local_declaration] = sym_local_declaration,
  [sym_global_declaration] = sym_global_declaration,
  [sym_table_constructor] = sym_table_constructor,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_local_declaration_repeat1] = aux_sym_local_declaration_repeat1,
  [aux_sym_local_declaration_repeat2] = aux_sym_local_declaration_repeat2,
  [aux_sym_table_constructor_repeat1] = aux_sym_table_constructor_repeat1,
  [aux_sym_table_constructor_repeat2] = aux_sym_table_constructor_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_local] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_global] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_local_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_global_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_table_constructor] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_local_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_local_declaration_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_constructor_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_constructor_repeat2] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_table_expr_key = 1,
  field_table_key = 2,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_table_expr_key] = "table_expr_key",
  [field_table_key] = "table_key",
};

static const TSFieldMapSlice ts_field_map_slices[5] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 4},
  [3] = {.index = 6, .length = 1},
  [4] = {.index = 7, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_table_expr_key, 1, .inherited = true},
    {field_table_key, 1, .inherited = true},
  [2] =
    {field_table_expr_key, 0, .inherited = true},
    {field_table_expr_key, 1, .inherited = true},
    {field_table_key, 0, .inherited = true},
    {field_table_key, 1, .inherited = true},
  [6] =
    {field_table_key, 0},
  [7] =
    {field_table_expr_key, 1},
};

static TSSymbol ts_alias_sequences[5][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(12);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == ',') ADVANCE(14);
      if (lookahead == ';') ADVANCE(18);
      if (lookahead == '=') ADVANCE(15);
      if (lookahead == '[') ADVANCE(19);
      if (lookahead == ']') ADVANCE(20);
      if (lookahead == 'g') ADVANCE(9);
      if (lookahead == 'l') ADVANCE(10);
      if (lookahead == '{') ADVANCE(17);
      if (lookahead == '}') ADVANCE(21);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == ',') ADVANCE(14);
      if (lookahead == ';') ADVANCE(18);
      if (lookahead == '=') ADVANCE(15);
      if (lookahead == '[') ADVANCE(19);
      if (lookahead == '{') ADVANCE(17);
      if (lookahead == '}') ADVANCE(21);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(22);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(24);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(8);
      END_STATE();
    case 5:
      if (lookahead == 'b') ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == 'c') ADVANCE(3);
      END_STATE();
    case 7:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 8:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(6);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(5);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_local);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_global);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(22);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_local] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_global] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(53),
    [sym__statement] = STATE(18),
    [sym_local_declaration] = STATE(18),
    [sym_global_declaration] = STATE(18),
    [aux_sym_program_repeat1] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_local] = ACTIONS(5),
    [anon_sym_global] = ACTIONS(7),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(11), 1,
      anon_sym_LBRACK,
    ACTIONS(13), 1,
      anon_sym_RBRACE,
    ACTIONS(15), 1,
      sym_identifier,
    STATE(7), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(17), 2,
      sym_number,
      sym_string,
    STATE(6), 2,
      sym__expression,
      sym_table_constructor,
  [24] = 7,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(11), 1,
      anon_sym_LBRACK,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(19), 1,
      anon_sym_RBRACE,
    STATE(2), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(17), 2,
      sym_number,
      sym_string,
    STATE(6), 2,
      sym__expression,
      sym_table_constructor,
  [48] = 3,
    STATE(9), 1,
      aux_sym_table_constructor_repeat1,
    ACTIONS(21), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(23), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [64] = 7,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(11), 1,
      anon_sym_LBRACK,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(25), 1,
      anon_sym_RBRACE,
    STATE(7), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(17), 2,
      sym_number,
      sym_string,
    STATE(6), 2,
      sym__expression,
      sym_table_constructor,
  [88] = 3,
    STATE(4), 1,
      aux_sym_table_constructor_repeat1,
    ACTIONS(27), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(29), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [104] = 7,
    ACTIONS(31), 1,
      anon_sym_LBRACE,
    ACTIONS(34), 1,
      anon_sym_LBRACK,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    ACTIONS(39), 1,
      sym_identifier,
    STATE(7), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(42), 2,
      sym_number,
      sym_string,
    STATE(6), 2,
      sym__expression,
      sym_table_constructor,
  [128] = 7,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(11), 1,
      anon_sym_LBRACK,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(45), 1,
      anon_sym_RBRACE,
    STATE(5), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(17), 2,
      sym_number,
      sym_string,
    STATE(6), 2,
      sym__expression,
      sym_table_constructor,
  [152] = 3,
    STATE(9), 1,
      aux_sym_table_constructor_repeat1,
    ACTIONS(47), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(50), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [168] = 2,
    ACTIONS(54), 1,
      anon_sym_EQ,
    ACTIONS(52), 8,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [182] = 2,
    ACTIONS(56), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(58), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [195] = 1,
    ACTIONS(60), 8,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [206] = 1,
    ACTIONS(62), 8,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [217] = 2,
    ACTIONS(64), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(66), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [230] = 4,
    ACTIONS(68), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
    STATE(17), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(71), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [247] = 4,
    ACTIONS(74), 1,
      anon_sym_LBRACE,
    ACTIONS(77), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
    STATE(17), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(79), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [264] = 1,
    ACTIONS(50), 8,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [275] = 4,
    ACTIONS(5), 1,
      anon_sym_local,
    ACTIONS(7), 1,
      anon_sym_global,
    ACTIONS(82), 1,
      ts_builtin_sym_end,
    STATE(19), 4,
      sym__statement,
      sym_local_declaration,
      sym_global_declaration,
      aux_sym_program_repeat1,
  [291] = 4,
    ACTIONS(84), 1,
      ts_builtin_sym_end,
    ACTIONS(86), 1,
      anon_sym_local,
    ACTIONS(89), 1,
      anon_sym_global,
    STATE(19), 4,
      sym__statement,
      sym_local_declaration,
      sym_global_declaration,
      aux_sym_program_repeat1,
  [307] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(14), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(92), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [320] = 3,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(50), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(96), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [333] = 3,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(34), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(98), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [346] = 1,
    ACTIONS(100), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [355] = 3,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(37), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(102), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [368] = 1,
    ACTIONS(104), 6,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_identifier,
      sym_number,
      sym_string,
  [377] = 3,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(42), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(106), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [390] = 3,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(39), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(108), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [403] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(11), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(110), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [416] = 3,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(17), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(112), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [429] = 3,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(36), 2,
      sym__expression,
      sym_table_constructor,
    ACTIONS(114), 3,
      sym_identifier,
      sym_number,
      sym_string,
  [442] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(116), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [454] = 1,
    ACTIONS(62), 5,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_COMMA,
      anon_sym_global,
      anon_sym_RBRACK,
  [462] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(120), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [474] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(40), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(120), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [486] = 1,
    ACTIONS(60), 5,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_COMMA,
      anon_sym_global,
      anon_sym_RBRACK,
  [494] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(41), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(122), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [506] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(31), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(124), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [518] = 3,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(126), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [530] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(33), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(131), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [542] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(133), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [554] = 3,
    ACTIONS(118), 1,
      anon_sym_COMMA,
    STATE(38), 1,
      aux_sym_local_declaration_repeat2,
    ACTIONS(124), 3,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_global,
  [566] = 1,
    ACTIONS(126), 4,
      ts_builtin_sym_end,
      anon_sym_local,
      anon_sym_COMMA,
      anon_sym_global,
  [573] = 3,
    ACTIONS(135), 1,
      anon_sym_COMMA,
    ACTIONS(138), 1,
      anon_sym_EQ,
    STATE(43), 1,
      aux_sym_local_declaration_repeat1,
  [583] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(142), 1,
      anon_sym_EQ,
    STATE(43), 1,
      aux_sym_local_declaration_repeat1,
  [593] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(144), 1,
      anon_sym_EQ,
    STATE(43), 1,
      aux_sym_local_declaration_repeat1,
  [603] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(146), 1,
      anon_sym_EQ,
    STATE(44), 1,
      aux_sym_local_declaration_repeat1,
  [613] = 3,
    ACTIONS(140), 1,
      anon_sym_COMMA,
    ACTIONS(148), 1,
      anon_sym_EQ,
    STATE(45), 1,
      aux_sym_local_declaration_repeat1,
  [623] = 1,
    ACTIONS(138), 2,
      anon_sym_COMMA,
      anon_sym_EQ,
  [628] = 1,
    ACTIONS(150), 1,
      anon_sym_EQ,
  [632] = 1,
    ACTIONS(152), 1,
      anon_sym_RBRACK,
  [636] = 1,
    ACTIONS(154), 1,
      sym_identifier,
  [640] = 1,
    ACTIONS(156), 1,
      sym_identifier,
  [644] = 1,
    ACTIONS(158), 1,
      ts_builtin_sym_end,
  [648] = 1,
    ACTIONS(160), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 64,
  [SMALL_STATE(6)] = 88,
  [SMALL_STATE(7)] = 104,
  [SMALL_STATE(8)] = 128,
  [SMALL_STATE(9)] = 152,
  [SMALL_STATE(10)] = 168,
  [SMALL_STATE(11)] = 182,
  [SMALL_STATE(12)] = 195,
  [SMALL_STATE(13)] = 206,
  [SMALL_STATE(14)] = 217,
  [SMALL_STATE(15)] = 230,
  [SMALL_STATE(16)] = 247,
  [SMALL_STATE(17)] = 264,
  [SMALL_STATE(18)] = 275,
  [SMALL_STATE(19)] = 291,
  [SMALL_STATE(20)] = 307,
  [SMALL_STATE(21)] = 320,
  [SMALL_STATE(22)] = 333,
  [SMALL_STATE(23)] = 346,
  [SMALL_STATE(24)] = 355,
  [SMALL_STATE(25)] = 368,
  [SMALL_STATE(26)] = 377,
  [SMALL_STATE(27)] = 390,
  [SMALL_STATE(28)] = 403,
  [SMALL_STATE(29)] = 416,
  [SMALL_STATE(30)] = 429,
  [SMALL_STATE(31)] = 442,
  [SMALL_STATE(32)] = 454,
  [SMALL_STATE(33)] = 462,
  [SMALL_STATE(34)] = 474,
  [SMALL_STATE(35)] = 486,
  [SMALL_STATE(36)] = 494,
  [SMALL_STATE(37)] = 506,
  [SMALL_STATE(38)] = 518,
  [SMALL_STATE(39)] = 530,
  [SMALL_STATE(40)] = 542,
  [SMALL_STATE(41)] = 554,
  [SMALL_STATE(42)] = 566,
  [SMALL_STATE(43)] = 573,
  [SMALL_STATE(44)] = 583,
  [SMALL_STATE(45)] = 593,
  [SMALL_STATE(46)] = 603,
  [SMALL_STATE(47)] = 613,
  [SMALL_STATE(48)] = 623,
  [SMALL_STATE(49)] = 628,
  [SMALL_STATE(50)] = 632,
  [SMALL_STATE(51)] = 636,
  [SMALL_STATE(52)] = 640,
  [SMALL_STATE(53)] = 644,
  [SMALL_STATE(54)] = 648,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 1),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(3),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(21),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(10),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(6),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat1, 2), SHIFT_REPEAT(29),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat1, 2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3, .production_id = 3),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_constructor, 3, .production_id = 1),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_constructor, 2),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 5, .production_id = 4),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2), SHIFT(3),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2), SHIFT(17),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3), SHIFT(3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3), SHIFT(17),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(51),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(54),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 6, .production_id = 4),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 4, .production_id = 3),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_local_declaration, 6),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_global_declaration, 5),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_local_declaration, 4),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_local_declaration, 5),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_local_declaration_repeat2, 2),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_local_declaration_repeat2, 2), SHIFT_REPEAT(26),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_global_declaration, 4),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_global_declaration, 6),
  [135] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_local_declaration_repeat1, 2), SHIFT_REPEAT(52),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_local_declaration_repeat1, 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [158] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_Teal(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
