#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 119
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 39
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 9

enum {
  anon_sym_return = 1,
  anon_sym_COMMA = 2,
  anon_sym_local = 3,
  anon_sym_global = 4,
  anon_sym_EQ = 5,
  anon_sym_LBRACE = 6,
  anon_sym_SEMI = 7,
  anon_sym_LBRACK = 8,
  anon_sym_RBRACK = 9,
  anon_sym_RBRACE = 10,
  anon_sym_function = 11,
  anon_sym_LPAREN = 12,
  anon_sym_RPAREN = 13,
  anon_sym_end = 14,
  anon_sym_COLON = 15,
  anon_sym_DOT = 16,
  sym_identifier = 17,
  sym_number = 18,
  sym_string = 19,
  sym_program = 20,
  sym__statement = 21,
  sym_retstat = 22,
  sym__expression = 23,
  sym_var_declaration = 24,
  sym_table_constructor = 25,
  sym_function_declaration = 26,
  sym_anon_function = 27,
  sym_type_annotation = 28,
  sym__type = 29,
  sym_simple_type = 30,
  sym_table_type = 31,
  aux_sym_program_repeat1 = 32,
  aux_sym_retstat_repeat1 = 33,
  aux_sym_var_declaration_repeat1 = 34,
  aux_sym_table_constructor_repeat1 = 35,
  aux_sym_table_constructor_repeat2 = 36,
  aux_sym_type_annotation_repeat1 = 37,
  aux_sym_simple_type_repeat1 = 38,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_return] = "return",
  [anon_sym_COMMA] = ",",
  [anon_sym_local] = "local",
  [anon_sym_global] = "global",
  [anon_sym_EQ] = "=",
  [anon_sym_LBRACE] = "{",
  [anon_sym_SEMI] = ";",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_RBRACE] = "}",
  [anon_sym_function] = "function",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_end] = "end",
  [anon_sym_COLON] = ":",
  [anon_sym_DOT] = ".",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym_string] = "string",
  [sym_program] = "program",
  [sym__statement] = "_statement",
  [sym_retstat] = "retstat",
  [sym__expression] = "_expression",
  [sym_var_declaration] = "var_declaration",
  [sym_table_constructor] = "table_constructor",
  [sym_function_declaration] = "function_declaration",
  [sym_anon_function] = "anon_function",
  [sym_type_annotation] = "type_annotation",
  [sym__type] = "_type",
  [sym_simple_type] = "simple_type",
  [sym_table_type] = "table_type",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_retstat_repeat1] = "retstat_repeat1",
  [aux_sym_var_declaration_repeat1] = "var_declaration_repeat1",
  [aux_sym_table_constructor_repeat1] = "table_constructor_repeat1",
  [aux_sym_table_constructor_repeat2] = "table_constructor_repeat2",
  [aux_sym_type_annotation_repeat1] = "type_annotation_repeat1",
  [aux_sym_simple_type_repeat1] = "simple_type_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_local] = anon_sym_local,
  [anon_sym_global] = anon_sym_global,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_end] = anon_sym_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_identifier] = sym_identifier,
  [sym_number] = sym_number,
  [sym_string] = sym_string,
  [sym_program] = sym_program,
  [sym__statement] = sym__statement,
  [sym_retstat] = sym_retstat,
  [sym__expression] = sym__expression,
  [sym_var_declaration] = sym_var_declaration,
  [sym_table_constructor] = sym_table_constructor,
  [sym_function_declaration] = sym_function_declaration,
  [sym_anon_function] = sym_anon_function,
  [sym_type_annotation] = sym_type_annotation,
  [sym__type] = sym__type,
  [sym_simple_type] = sym_simple_type,
  [sym_table_type] = sym_table_type,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_retstat_repeat1] = aux_sym_retstat_repeat1,
  [aux_sym_var_declaration_repeat1] = aux_sym_var_declaration_repeat1,
  [aux_sym_table_constructor_repeat1] = aux_sym_table_constructor_repeat1,
  [aux_sym_table_constructor_repeat2] = aux_sym_table_constructor_repeat2,
  [aux_sym_type_annotation_repeat1] = aux_sym_type_annotation_repeat1,
  [aux_sym_simple_type_repeat1] = aux_sym_simple_type_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_local] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_global] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
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
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_end] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
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
  [sym_retstat] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_var_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_table_constructor] = {
    .visible = true,
    .named = true,
  },
  [sym_function_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_anon_function] = {
    .visible = true,
    .named = true,
  },
  [sym_type_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_simple_type] = {
    .visible = true,
    .named = true,
  },
  [sym_table_type] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_retstat_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_var_declaration_repeat1] = {
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
  [aux_sym_type_annotation_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_simple_type_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_arg = 1,
  field_function_name = 2,
  field_table_expr_key = 3,
  field_table_key = 4,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_arg] = "arg",
  [field_function_name] = "function_name",
  [field_table_expr_key] = "table_expr_key",
  [field_table_key] = "table_key",
};

static const TSFieldMapSlice ts_field_map_slices[8] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 4},
  [3] = {.index = 6, .length = 1},
  [4] = {.index = 7, .length = 1},
  [5] = {.index = 8, .length = 1},
  [6] = {.index = 9, .length = 1},
  [7] = {.index = 10, .length = 2},
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
    {field_arg, 2},
  [8] =
    {field_function_name, 2},
  [9] =
    {field_table_expr_key, 1},
  [10] =
    {field_arg, 4},
    {field_function_name, 2},
};

static TSSymbol ts_alias_sequences[8][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == '(') ADVANCE(37);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == ',') ADVANCE(25);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == ':') ADVANCE(41);
      if (lookahead == ';') ADVANCE(32);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '[') ADVANCE(33);
      if (lookahead == ']') ADVANCE(34);
      if (lookahead == 'e') ADVANCE(54);
      if (lookahead == 'f') ADVANCE(65);
      if (lookahead == 'g') ADVANCE(53);
      if (lookahead == 'l') ADVANCE(58);
      if (lookahead == 'r') ADVANCE(49);
      if (lookahead == '{') ADVANCE(31);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == ',') ADVANCE(25);
      if (lookahead == ';') ADVANCE(32);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == '[') ADVANCE(33);
      if (lookahead == 'f') ADVANCE(65);
      if (lookahead == '{') ADVANCE(31);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(68);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == '{') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(10);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(11);
      END_STATE();
    case 6:
      if (lookahead == 'b') ADVANCE(5);
      END_STATE();
    case 7:
      if (lookahead == 'c') ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == 'd') ADVANCE(39);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(8);
      END_STATE();
    case 14:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(6);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 20:
      if (eof) ADVANCE(22);
      if (lookahead == '"') ADVANCE(2);
      if (lookahead == 'f') ADVANCE(65);
      if (lookahead == 'g') ADVANCE(53);
      if (lookahead == 'l') ADVANCE(58);
      if (lookahead == 'r') ADVANCE(49);
      if (lookahead == '{') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == ')') ADVANCE(38);
      if (lookahead == ',') ADVANCE(25);
      if (lookahead == '.') ADVANCE(42);
      if (lookahead == ':') ADVANCE(41);
      if (lookahead == '=') ADVANCE(30);
      if (lookahead == ']') ADVANCE(34);
      if (lookahead == 'e') ADVANCE(13);
      if (lookahead == 'g') ADVANCE(12);
      if (lookahead == 'l') ADVANCE(15);
      if (lookahead == 'r') ADVANCE(9);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(21)
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_local);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_local);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_global);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_global);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_function);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_end);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_end);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 21},
  [2] = {.lex_state = 20},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 21},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 21},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 21},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 21},
  [13] = {.lex_state = 21},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 21},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 21},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 21},
  [25] = {.lex_state = 21},
  [26] = {.lex_state = 21},
  [27] = {.lex_state = 21},
  [28] = {.lex_state = 21},
  [29] = {.lex_state = 21},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 21},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 21},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 21},
  [36] = {.lex_state = 21},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 21},
  [39] = {.lex_state = 21},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 21},
  [42] = {.lex_state = 21},
  [43] = {.lex_state = 21},
  [44] = {.lex_state = 21},
  [45] = {.lex_state = 21},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 21},
  [49] = {.lex_state = 21},
  [50] = {.lex_state = 21},
  [51] = {.lex_state = 21},
  [52] = {.lex_state = 21},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 21},
  [55] = {.lex_state = 21},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 21},
  [61] = {.lex_state = 21},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 21},
  [67] = {.lex_state = 21},
  [68] = {.lex_state = 21},
  [69] = {.lex_state = 21},
  [70] = {.lex_state = 21},
  [71] = {.lex_state = 21},
  [72] = {.lex_state = 21},
  [73] = {.lex_state = 21},
  [74] = {.lex_state = 21},
  [75] = {.lex_state = 21},
  [76] = {.lex_state = 21},
  [77] = {.lex_state = 21},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 21},
  [80] = {.lex_state = 21},
  [81] = {.lex_state = 21},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 21},
  [84] = {.lex_state = 21},
  [85] = {.lex_state = 21},
  [86] = {.lex_state = 21},
  [87] = {.lex_state = 21},
  [88] = {.lex_state = 21},
  [89] = {.lex_state = 21},
  [90] = {.lex_state = 3},
  [91] = {.lex_state = 21},
  [92] = {.lex_state = 3},
  [93] = {.lex_state = 21},
  [94] = {.lex_state = 21},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 3},
  [97] = {.lex_state = 21},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 3},
  [108] = {.lex_state = 3},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 3},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_local] = ACTIONS(1),
    [anon_sym_global] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(114),
    [sym__statement] = STATE(35),
    [sym_retstat] = STATE(35),
    [sym_var_declaration] = STATE(35),
    [sym_function_declaration] = STATE(35),
    [aux_sym_program_repeat1] = STATE(35),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_return] = ACTIONS(5),
    [anon_sym_local] = ACTIONS(7),
    [anon_sym_global] = ACTIONS(7),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 2,
      sym_number,
      sym_string,
    ACTIONS(11), 3,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
    STATE(83), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [27] = 6,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 2,
      sym_number,
      sym_string,
    STATE(83), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
    ACTIONS(11), 4,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [52] = 8,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(25), 1,
      anon_sym_RBRACE,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(6), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(31), 2,
      sym_number,
      sym_string,
    STATE(15), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [80] = 3,
    ACTIONS(35), 1,
      anon_sym_DOT,
    STATE(5), 1,
      aux_sym_simple_type_repeat1,
    ACTIONS(33), 9,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RBRACE,
      anon_sym_end,
      anon_sym_COLON,
  [98] = 8,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(38), 1,
      anon_sym_RBRACE,
    STATE(9), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(31), 2,
      sym_number,
      sym_string,
    STATE(15), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [126] = 8,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(40), 1,
      anon_sym_RBRACE,
    STATE(11), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(31), 2,
      sym_number,
      sym_string,
    STATE(15), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [154] = 3,
    ACTIONS(44), 1,
      anon_sym_DOT,
    STATE(5), 1,
      aux_sym_simple_type_repeat1,
    ACTIONS(42), 9,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RBRACE,
      anon_sym_end,
      anon_sym_COLON,
  [172] = 8,
    ACTIONS(46), 1,
      anon_sym_LBRACE,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_RBRACE,
    ACTIONS(54), 1,
      anon_sym_function,
    ACTIONS(57), 1,
      sym_identifier,
    STATE(9), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(60), 2,
      sym_number,
      sym_string,
    STATE(15), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [200] = 3,
    ACTIONS(44), 1,
      anon_sym_DOT,
    STATE(8), 1,
      aux_sym_simple_type_repeat1,
    ACTIONS(63), 9,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RBRACE,
      anon_sym_end,
      anon_sym_COLON,
  [218] = 8,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    STATE(9), 1,
      aux_sym_table_constructor_repeat2,
    ACTIONS(31), 2,
      sym_number,
      sym_string,
    STATE(15), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [246] = 6,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(71), 1,
      anon_sym_EQ,
    ACTIONS(73), 1,
      anon_sym_COLON,
    STATE(18), 1,
      aux_sym_var_declaration_repeat1,
    STATE(86), 1,
      sym_type_annotation,
    ACTIONS(67), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [269] = 1,
    ACTIONS(33), 10,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RBRACE,
      anon_sym_end,
      anon_sym_COLON,
      anon_sym_DOT,
  [282] = 3,
    ACTIONS(77), 1,
      anon_sym_EQ,
    ACTIONS(79), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(75), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [299] = 4,
    STATE(17), 1,
      aux_sym_table_constructor_repeat1,
    ACTIONS(81), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(85), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(83), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [318] = 3,
    ACTIONS(89), 1,
      anon_sym_COMMA,
    STATE(16), 1,
      aux_sym_var_declaration_repeat1,
    ACTIONS(87), 8,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_COLON,
  [335] = 4,
    STATE(21), 1,
      aux_sym_table_constructor_repeat1,
    ACTIONS(92), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(96), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(94), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [354] = 6,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(73), 1,
      anon_sym_COLON,
    ACTIONS(100), 1,
      anon_sym_EQ,
    STATE(16), 1,
      aux_sym_var_declaration_repeat1,
    STATE(88), 1,
      sym_type_annotation,
    ACTIONS(98), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [377] = 6,
    ACTIONS(102), 1,
      anon_sym_LBRACE,
    ACTIONS(107), 1,
      anon_sym_function,
    ACTIONS(110), 1,
      sym_identifier,
    ACTIONS(105), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
    ACTIONS(113), 2,
      sym_number,
      sym_string,
    STATE(47), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [400] = 6,
    ACTIONS(116), 1,
      anon_sym_LBRACE,
    ACTIONS(119), 1,
      anon_sym_function,
    ACTIONS(122), 1,
      sym_identifier,
    ACTIONS(94), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
    ACTIONS(125), 2,
      sym_number,
      sym_string,
    STATE(47), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [423] = 4,
    STATE(21), 1,
      aux_sym_table_constructor_repeat1,
    ACTIONS(128), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(133), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(131), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [442] = 2,
    ACTIONS(137), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(135), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [456] = 2,
    ACTIONS(141), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(139), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [470] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(145), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [488] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(147), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [506] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(149), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(25), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [524] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(151), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(24), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [542] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(149), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [560] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(153), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(44), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [578] = 2,
    ACTIONS(157), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(155), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [592] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(159), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [610] = 3,
    ACTIONS(161), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(165), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(163), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [626] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(167), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(51), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [644] = 2,
    ACTIONS(171), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(169), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [658] = 4,
    ACTIONS(5), 1,
      anon_sym_return,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(49), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [676] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(153), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [694] = 2,
    ACTIONS(177), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(175), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [708] = 1,
    ACTIONS(87), 9,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RPAREN,
      anon_sym_end,
      anon_sym_COLON,
  [720] = 1,
    ACTIONS(179), 9,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RBRACE,
      anon_sym_end,
      anon_sym_COLON,
  [732] = 2,
    ACTIONS(183), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(181), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [746] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(185), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(28), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [764] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(187), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [782] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(189), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(31), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [800] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(191), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [818] = 1,
    ACTIONS(193), 9,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_RBRACE,
      anon_sym_end,
      anon_sym_COLON,
  [830] = 3,
    ACTIONS(195), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
    ACTIONS(199), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(197), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [846] = 2,
    ACTIONS(133), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(131), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [860] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(189), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [878] = 4,
    ACTIONS(201), 1,
      ts_builtin_sym_end,
    ACTIONS(203), 1,
      anon_sym_return,
    ACTIONS(206), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(49), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [896] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(209), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(36), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [914] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(211), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [932] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(213), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(48), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [950] = 2,
    ACTIONS(217), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(215), 7,
      anon_sym_COMMA,
      anon_sym_LBRACE,
      anon_sym_SEMI,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [964] = 4,
    ACTIONS(143), 1,
      anon_sym_return,
    ACTIONS(219), 1,
      anon_sym_end,
    ACTIONS(7), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(42), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [982] = 4,
    ACTIONS(201), 1,
      anon_sym_end,
    ACTIONS(221), 1,
      anon_sym_return,
    ACTIONS(206), 2,
      anon_sym_local,
      anon_sym_global,
    STATE(55), 5,
      sym__statement,
      sym_retstat,
      sym_var_declaration,
      sym_function_declaration,
      aux_sym_program_repeat1,
  [1000] = 5,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(224), 1,
      sym_identifier,
    ACTIONS(226), 2,
      sym_number,
      sym_string,
    STATE(81), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1019] = 5,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(228), 1,
      sym_identifier,
    ACTIONS(230), 2,
      sym_number,
      sym_string,
    STATE(87), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1038] = 5,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(232), 1,
      sym_identifier,
    ACTIONS(234), 2,
      sym_number,
      sym_string,
    STATE(67), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1057] = 5,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(236), 1,
      sym_identifier,
    ACTIONS(238), 2,
      sym_number,
      sym_string,
    STATE(46), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1076] = 3,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    STATE(61), 1,
      aux_sym_type_annotation_repeat1,
    ACTIONS(240), 6,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_end,
  [1091] = 3,
    ACTIONS(246), 1,
      anon_sym_COMMA,
    STATE(61), 1,
      aux_sym_type_annotation_repeat1,
    ACTIONS(244), 6,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_end,
  [1106] = 5,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(249), 1,
      sym_identifier,
    ACTIONS(251), 2,
      sym_number,
      sym_string,
    STATE(68), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1125] = 5,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(253), 1,
      sym_identifier,
    ACTIONS(255), 2,
      sym_number,
      sym_string,
    STATE(32), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1144] = 5,
    ACTIONS(13), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      anon_sym_function,
    ACTIONS(257), 1,
      sym_identifier,
    ACTIONS(259), 2,
      sym_number,
      sym_string,
    STATE(116), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1163] = 5,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(27), 1,
      anon_sym_function,
    ACTIONS(261), 1,
      sym_identifier,
    ACTIONS(263), 2,
      sym_number,
      sym_string,
    STATE(47), 3,
      sym__expression,
      sym_table_constructor,
      sym_anon_function,
  [1182] = 3,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    STATE(60), 1,
      aux_sym_type_annotation_repeat1,
    ACTIONS(265), 6,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_end,
  [1197] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(72), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(267), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1211] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(85), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(271), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1225] = 1,
    ACTIONS(181), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1235] = 1,
    ACTIONS(175), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1245] = 1,
    ACTIONS(135), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1255] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(73), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(273), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1269] = 3,
    ACTIONS(277), 1,
      anon_sym_COMMA,
    STATE(73), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(275), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1283] = 1,
    ACTIONS(155), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1293] = 1,
    ACTIONS(244), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_EQ,
      anon_sym_end,
  [1303] = 1,
    ACTIONS(139), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1313] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(73), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(271), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1327] = 2,
    ACTIONS(282), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(280), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [1339] = 1,
    ACTIONS(215), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1349] = 1,
    ACTIONS(169), 7,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_RBRACK,
      anon_sym_end,
  [1359] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(77), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(273), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1373] = 2,
    ACTIONS(286), 2,
      anon_sym_function,
      sym_identifier,
    ACTIONS(284), 5,
      anon_sym_LBRACE,
      anon_sym_LBRACK,
      anon_sym_RBRACE,
      sym_number,
      sym_string,
  [1385] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(84), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(288), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1399] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(73), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(290), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1413] = 3,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    STATE(73), 1,
      aux_sym_retstat_repeat1,
    ACTIONS(292), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1427] = 2,
    ACTIONS(100), 1,
      anon_sym_EQ,
    ACTIONS(98), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1438] = 1,
    ACTIONS(275), 6,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_COMMA,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1447] = 2,
    ACTIONS(294), 1,
      anon_sym_EQ,
    ACTIONS(267), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1458] = 1,
    ACTIONS(296), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1466] = 3,
    ACTIONS(298), 1,
      anon_sym_LBRACE,
    ACTIONS(300), 1,
      sym_identifier,
    STATE(105), 3,
      sym__type,
      sym_simple_type,
      sym_table_type,
  [1478] = 1,
    ACTIONS(302), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1486] = 3,
    ACTIONS(298), 1,
      anon_sym_LBRACE,
    ACTIONS(300), 1,
      sym_identifier,
    STATE(66), 3,
      sym__type,
      sym_simple_type,
      sym_table_type,
  [1498] = 1,
    ACTIONS(304), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1506] = 1,
    ACTIONS(306), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1514] = 3,
    ACTIONS(298), 1,
      anon_sym_LBRACE,
    ACTIONS(300), 1,
      sym_identifier,
    STATE(75), 3,
      sym__type,
      sym_simple_type,
      sym_table_type,
  [1526] = 3,
    ACTIONS(298), 1,
      anon_sym_LBRACE,
    ACTIONS(300), 1,
      sym_identifier,
    STATE(117), 3,
      sym__type,
      sym_simple_type,
      sym_table_type,
  [1538] = 1,
    ACTIONS(308), 5,
      ts_builtin_sym_end,
      anon_sym_return,
      anon_sym_local,
      anon_sym_global,
      anon_sym_end,
  [1546] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(310), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      aux_sym_var_declaration_repeat1,
  [1556] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(312), 1,
      anon_sym_RPAREN,
    STATE(103), 1,
      aux_sym_var_declaration_repeat1,
  [1566] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      aux_sym_var_declaration_repeat1,
  [1576] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(316), 1,
      anon_sym_RPAREN,
    STATE(98), 1,
      aux_sym_var_declaration_repeat1,
  [1586] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(318), 1,
      anon_sym_RPAREN,
    STATE(100), 1,
      aux_sym_var_declaration_repeat1,
  [1596] = 3,
    ACTIONS(69), 1,
      anon_sym_COMMA,
    ACTIONS(320), 1,
      anon_sym_RPAREN,
    STATE(16), 1,
      aux_sym_var_declaration_repeat1,
  [1606] = 2,
    ACTIONS(322), 1,
      anon_sym_RPAREN,
    ACTIONS(324), 1,
      sym_identifier,
  [1613] = 2,
    ACTIONS(326), 1,
      anon_sym_RBRACE,
    ACTIONS(328), 1,
      anon_sym_COLON,
  [1620] = 2,
    ACTIONS(330), 1,
      anon_sym_function,
    ACTIONS(332), 1,
      sym_identifier,
  [1627] = 2,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    ACTIONS(336), 1,
      sym_identifier,
  [1634] = 2,
    ACTIONS(338), 1,
      anon_sym_RPAREN,
    ACTIONS(340), 1,
      sym_identifier,
  [1641] = 1,
    ACTIONS(342), 1,
      anon_sym_EQ,
  [1645] = 1,
    ACTIONS(344), 1,
      anon_sym_LPAREN,
  [1649] = 1,
    ACTIONS(346), 1,
      sym_identifier,
  [1653] = 1,
    ACTIONS(348), 1,
      sym_identifier,
  [1657] = 1,
    ACTIONS(350), 1,
      anon_sym_LPAREN,
  [1661] = 1,
    ACTIONS(352), 1,
      ts_builtin_sym_end,
  [1665] = 1,
    ACTIONS(354), 1,
      sym_identifier,
  [1669] = 1,
    ACTIONS(356), 1,
      anon_sym_RBRACK,
  [1673] = 1,
    ACTIONS(358), 1,
      anon_sym_RBRACE,
  [1677] = 1,
    ACTIONS(360), 1,
      anon_sym_LPAREN,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 80,
  [SMALL_STATE(6)] = 98,
  [SMALL_STATE(7)] = 126,
  [SMALL_STATE(8)] = 154,
  [SMALL_STATE(9)] = 172,
  [SMALL_STATE(10)] = 200,
  [SMALL_STATE(11)] = 218,
  [SMALL_STATE(12)] = 246,
  [SMALL_STATE(13)] = 269,
  [SMALL_STATE(14)] = 282,
  [SMALL_STATE(15)] = 299,
  [SMALL_STATE(16)] = 318,
  [SMALL_STATE(17)] = 335,
  [SMALL_STATE(18)] = 354,
  [SMALL_STATE(19)] = 377,
  [SMALL_STATE(20)] = 400,
  [SMALL_STATE(21)] = 423,
  [SMALL_STATE(22)] = 442,
  [SMALL_STATE(23)] = 456,
  [SMALL_STATE(24)] = 470,
  [SMALL_STATE(25)] = 488,
  [SMALL_STATE(26)] = 506,
  [SMALL_STATE(27)] = 524,
  [SMALL_STATE(28)] = 542,
  [SMALL_STATE(29)] = 560,
  [SMALL_STATE(30)] = 578,
  [SMALL_STATE(31)] = 592,
  [SMALL_STATE(32)] = 610,
  [SMALL_STATE(33)] = 626,
  [SMALL_STATE(34)] = 644,
  [SMALL_STATE(35)] = 658,
  [SMALL_STATE(36)] = 676,
  [SMALL_STATE(37)] = 694,
  [SMALL_STATE(38)] = 708,
  [SMALL_STATE(39)] = 720,
  [SMALL_STATE(40)] = 732,
  [SMALL_STATE(41)] = 746,
  [SMALL_STATE(42)] = 764,
  [SMALL_STATE(43)] = 782,
  [SMALL_STATE(44)] = 800,
  [SMALL_STATE(45)] = 818,
  [SMALL_STATE(46)] = 830,
  [SMALL_STATE(47)] = 846,
  [SMALL_STATE(48)] = 860,
  [SMALL_STATE(49)] = 878,
  [SMALL_STATE(50)] = 896,
  [SMALL_STATE(51)] = 914,
  [SMALL_STATE(52)] = 932,
  [SMALL_STATE(53)] = 950,
  [SMALL_STATE(54)] = 964,
  [SMALL_STATE(55)] = 982,
  [SMALL_STATE(56)] = 1000,
  [SMALL_STATE(57)] = 1019,
  [SMALL_STATE(58)] = 1038,
  [SMALL_STATE(59)] = 1057,
  [SMALL_STATE(60)] = 1076,
  [SMALL_STATE(61)] = 1091,
  [SMALL_STATE(62)] = 1106,
  [SMALL_STATE(63)] = 1125,
  [SMALL_STATE(64)] = 1144,
  [SMALL_STATE(65)] = 1163,
  [SMALL_STATE(66)] = 1182,
  [SMALL_STATE(67)] = 1197,
  [SMALL_STATE(68)] = 1211,
  [SMALL_STATE(69)] = 1225,
  [SMALL_STATE(70)] = 1235,
  [SMALL_STATE(71)] = 1245,
  [SMALL_STATE(72)] = 1255,
  [SMALL_STATE(73)] = 1269,
  [SMALL_STATE(74)] = 1283,
  [SMALL_STATE(75)] = 1293,
  [SMALL_STATE(76)] = 1303,
  [SMALL_STATE(77)] = 1313,
  [SMALL_STATE(78)] = 1327,
  [SMALL_STATE(79)] = 1339,
  [SMALL_STATE(80)] = 1349,
  [SMALL_STATE(81)] = 1359,
  [SMALL_STATE(82)] = 1373,
  [SMALL_STATE(83)] = 1385,
  [SMALL_STATE(84)] = 1399,
  [SMALL_STATE(85)] = 1413,
  [SMALL_STATE(86)] = 1427,
  [SMALL_STATE(87)] = 1438,
  [SMALL_STATE(88)] = 1447,
  [SMALL_STATE(89)] = 1458,
  [SMALL_STATE(90)] = 1466,
  [SMALL_STATE(91)] = 1478,
  [SMALL_STATE(92)] = 1486,
  [SMALL_STATE(93)] = 1498,
  [SMALL_STATE(94)] = 1506,
  [SMALL_STATE(95)] = 1514,
  [SMALL_STATE(96)] = 1526,
  [SMALL_STATE(97)] = 1538,
  [SMALL_STATE(98)] = 1546,
  [SMALL_STATE(99)] = 1556,
  [SMALL_STATE(100)] = 1566,
  [SMALL_STATE(101)] = 1576,
  [SMALL_STATE(102)] = 1586,
  [SMALL_STATE(103)] = 1596,
  [SMALL_STATE(104)] = 1606,
  [SMALL_STATE(105)] = 1613,
  [SMALL_STATE(106)] = 1620,
  [SMALL_STATE(107)] = 1627,
  [SMALL_STATE(108)] = 1634,
  [SMALL_STATE(109)] = 1641,
  [SMALL_STATE(110)] = 1645,
  [SMALL_STATE(111)] = 1649,
  [SMALL_STATE(112)] = 1653,
  [SMALL_STATE(113)] = 1657,
  [SMALL_STATE(114)] = 1661,
  [SMALL_STATE(115)] = 1665,
  [SMALL_STATE(116)] = 1669,
  [SMALL_STATE(117)] = 1673,
  [SMALL_STATE(118)] = 1677,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_retstat, 1),
  [11] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_retstat, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_simple_type_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_simple_type_repeat1, 2), SHIFT_REPEAT(115),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_type, 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(4),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(64),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(118),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(14),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2, .production_id = 2), SHIFT_REPEAT(15),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_type, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 2),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 1),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 1),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_var_declaration_repeat1, 2),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_var_declaration_repeat1, 2), SHIFT_REPEAT(111),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 2),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 3),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3), SHIFT(4),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 3), SHIFT(118),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 3), SHIFT(47),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3), SHIFT(47),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2), SHIFT(4),
  [119] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 2), SHIFT(118),
  [122] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 2), SHIFT(47),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 2), SHIFT(47),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat1, 2), SHIFT_REPEAT(65),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat1, 2),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat1, 2),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anon_function, 4),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anon_function, 4),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_constructor, 2),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_constructor, 2),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anon_function, 7, .production_id = 4),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anon_function, 7, .production_id = 4),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 5, .production_id = 6),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 5, .production_id = 6),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anon_function, 6, .production_id = 4),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anon_function, 6, .production_id = 4),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anon_function, 5, .production_id = 4),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anon_function, 5, .production_id = 4),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_type, 3),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anon_function, 5),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_anon_function, 5),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_type, 5),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 3, .production_id = 3),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 3, .production_id = 3),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [203] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(2),
  [206] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(106),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table_constructor, 3, .production_id = 1),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table_constructor, 3, .production_id = 1),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [221] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(3),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [232] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 3),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_annotation_repeat1, 2),
  [246] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_annotation_repeat1, 2), SHIFT_REPEAT(95),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [257] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_annotation, 2),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 4),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 6),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 5),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_retstat_repeat1, 2),
  [277] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_retstat_repeat1, 2), SHIFT_REPEAT(57),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 4, .production_id = 3),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 4, .production_id = 3),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_constructor_repeat2, 6, .production_id = 6),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_table_constructor_repeat2, 6, .production_id = 6),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_retstat, 2),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_retstat, 3),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 7),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 7, .production_id = 5),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 6, .production_id = 5),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 7, .production_id = 7),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 8, .production_id = 7),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 9, .production_id = 7),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [332] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [352] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
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
