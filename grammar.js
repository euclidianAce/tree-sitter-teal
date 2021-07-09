const list = (item, sep = ",") => seq(item, repeat(seq(sep, item)))

const prec_op = {
  or: 1,
  and: 2,
  is: 3,
  comp: 4,
  bor: 5,
  bnot: 6,
  band: 7,
  bshift: 8,
  concat: 9,
  plus: 10,
  mult: 11,
  unary: 12,
  power: 13,

  as: 100,

  index: 1000,
}

const prec_type_op = {
  union: 100,
  index: 1000,
}

module.exports = grammar({
  name: 'teal',

  extras: $ => [
    $.comment,
    /[\s\n]/,
  ],

  externals: $ => [
    $.comment,

    $._long_string_start,
    $._long_string_char,
    $._long_string_end,

    $._short_string_start,
    $._short_string_char,
    $._short_string_end,
  ],

  inline: $ => [
    $.scope,
    $._partypelist,
    $._parnamelist,
    $._type_list_maybe_vararg,
  ],

  conflicts : $ => [
    [$._var, $.table_entry], // conflict lies in table entries with type annotations vs array entry of a method call
                             // ex: { foo: bar = nil } vs { foo:bar() }
    [$.return_type],
  ],

  word: $ => $.identifier,

  rules: {
    program: $ => seq(
      alias(optional(token.immediate(/#![^\n\r]*/)), $.shebang_comment),
      repeat($._statement),
    ),

    _statement: $ => prec(1, seq(choice(
      $.var_declaration,
      $.var_assignment,
      $.type_declaration,
      $.record_declaration,
      $.enum_declaration,
      $.return_statement,
      $.break,
      $.for_statement,
      $.do_statement,
      $.while_statement,
      $.repeat_statement,
      $.function_call,
      $.function_statement,
      $.if_statement,
      seq("::", alias($.identifier, $.label), "::"),
      $.goto
    ), optional(";"))),

    return_statement: $ => prec.right(1, seq(
      'return',
      optional(choice(
        list($._expression),
        seq("(", list($._expression), ")")
      ))
    )),

    break: $ => 'break',

    if_statement: $ => seq(
      "if", field("condition", $._expression), "then",
      repeat($._statement),
      repeat($.elseif_block),
      optional($.else_block),
      "end"
    ),

    elseif_block: $ => seq("elseif", field("condition", $._expression), "then", repeat($._statement)),
    else_block: $ => seq("else", repeat($._statement)),

    for_statement: $ => choice(
      seq(
        "for", $.identifier, "=", $._expression, ",", $._expression, optional(seq(",", $._expression)), alias($.do_statement, $.for_body)
      ),
      seq(
        "for", list($.identifier), "in", list($._expression), alias($.do_statement, $.for_body)
      )
    ),

    while_statement: $ => seq(
      "while", field("condition", $._expression), alias($.do_statement, $.while_body)
    ),

    repeat_statement: $ => seq(
      "repeat", repeat($._statement),
      "until", field("condition", $._expression)
    ),

    do_statement: $ => seq(
      "do",
      repeat($._statement),
      "end"
    ),

    _expression: $ => choice(
      $.identifier,
      $._var,
      $.number,
      $.string,
      $.boolean,
      $.nil,
      $.table_constructor,
      $.anon_function,
      $.function_call,
      $._prefix_expression,
      $.bin_op,
      $.unary_op,
      $.varargs,
      $.type_cast,
    ),

    unary_op: $ => prec.left(prec_op.unary, seq(
      field("op", alias(choice('not', '#', '-', '~'), $.op)),
      $._expression
    )),

    bin_op: $ => choice(
      ...[
        ['or', prec_op.or],
        ['and', prec_op.and],
        ['<', prec_op.comp],
        ['<=', prec_op.comp],
        ['==', prec_op.comp],
        ['~=', prec_op.comp],
        ['>=', prec_op.comp],
        ['>', prec_op.comp],
        ['|', prec_op.bor],
        ['~', prec_op.bnot],
        ['&', prec_op.band],
        ['<<', prec_op.bshift],
        ['>>', prec_op.bshift],
        ['+', prec_op.plus],
        ['-', prec_op.plus],
        ['*', prec_op.mult],
        ['/', prec_op.mult],
        ['//', prec_op.mult],
        ['%', prec_op.mult],
      ].map(([operator, precedence]) => prec.left(precedence, seq(
        $._expression,
        field("op", alias(operator, $.op)),
        $._expression
      ))),
      ...[
        ['..', prec_op.concat],
        ['^', prec_op.power],
      ].map(([operator, precedence]) => prec.right(precedence, seq(
        $._expression,
        field("op", alias(operator, $.op)),
        $._expression
      ))),
      prec.right(prec_op.is, seq(
        $._expression,
        field("op", alias("is", $.op)),
        $._type
      )),
    ),

    type_cast: $ => prec.right(prec_op.as, seq(
      $._expression,
      "as",
      choice($._type, $.type_tuple)
    )),

    type_tuple: $ => prec(10, seq("(", list($._type), ")")),
    type_union: $ => prec.left(prec_type_op.union, seq($._type, "|", $._type)),

    var_declarator: $ => seq(
      field("name", $.identifier),
      optional(seq("<", field("attribute", alias($.identifier, $.attribute)), ">")),
    ),

    var_declarators: $ => list(alias($.var_declarator, $.var)),

    expressions: $ => list($._expression),

    var_declaration: $ => seq(
      $.scope,
      field("declarators", $.var_declarators),
      optional(field("type_annotation", $.type_annotation)),
      optional(seq("=", field("initializers", $.expressions)))
    ),

    type_declaration: $ => choice(
      seq(
        $.scope,
        "type",
        alias($.identifier, $.type_name),
        "=",
        choice(
          $._type, $._newtype
        )
      ),
      $.record_declaration,
      $.enum_declaration,
    ),

    assignment_variables: $ => list(alias($._var, $.var)),

    var_assignment: $ => seq(
      field("variables", $.assignment_variables), "=", field("expressions", $.expressions)
    ),

    _prefix_expression: $ => prec(10, choice(
      $._var,
      $.function_call,
      seq("(", $._expression, ")")
    )),
    method_index: $ => seq($._prefix_expression, ":", field("key", $.identifier)),
    arguments: $ => choice(
      seq("(", optional(list($._expression)), ")"),
      $.string,
      $.table_constructor
    ),
    function_call: $ => prec(10, seq(
      field("called_object", choice(
        $._prefix_expression,
        $.method_index
      )),
      field("arguments", $.arguments)
    )),

    table_entry: $ => choice(
      seq("[", field("expr_key", $._expression), "]", "=", field("value", $._expression)),
      prec(1, seq(
        field("key", $.identifier),
        field("type", optional(seq(":", $._type))),
        "=",
        field("value", $._expression)
      )),
      prec(1, field("value", $._expression)),
    ),

    table_constructor: $ => seq(
      "{",
      optional(list($.table_entry, choice(",", ";"))),
      optional(choice(",", ";")),
      "}"
    ),

    function_name: $ => seq(
      field("base", $.identifier),
      choice(
        seq(
          repeat(seq(".", field("entry", $.identifier))),
          seq(":", field("method", $.identifier))
        ),
        repeat1(seq(".", field("entry", $.identifier)))
      )
    ),

    scope: $ => field("scope", choice("local", "global")),

    function_statement: $ => choice(
      seq(
        $.scope,
        "function",
        field("name", $.identifier),
        field("signature", $.function_signature),
        field("body", $.function_body)
      ),
      seq(
        "function",
        field("name", $.function_name),
        field("signature", $.function_signature),
        field("body", $.function_body)
      )
    ),

    variadic_type: $ => prec(prec_type_op.index - 1, seq($._type, "...")),
    _type_list_maybe_vararg: $ => seq(list($._type), optional(seq(",", $.variadic_type))),
    return_type: $ => choice(
      $.variadic_type,
      prec.dynamic(1, $._type_list_maybe_vararg),
      prec.dynamic(10, seq("(", $._type_list_maybe_vararg, ")")),
    ),

    _partypelist: $ => list(alias($._partype, $.arg)),
    _partype: $ => seq(optional(seq(field("name", $.identifier), ":")), field("type", $._type)),
    _parnamelist: $ => list(alias($._parname, $.arg)),
    _parname: $ => seq(
      field("name", $.identifier),
      optional(seq(":", field("type", $._type)))
    ),
    typeargs: $ => seq("<", list($.identifier), ">"),

    anon_function: $ => seq(
      "function",
      field("signature", $.function_signature),
      field("body", $.function_body)
    ),

    _annotated_var_arg: $ => seq("...", ":", field("type", $._type)),
    signature_arguments: $ => seq("(",
      optional(choice(
        $._parnamelist,
        seq(
          $._parnamelist,
          ",",
          alias($._annotated_var_arg, $.varargs)
        ),
        alias($._annotated_var_arg, $.varargs)
      )),
      ")"
    ),

    function_signature: $ => seq(
      field("typeargs", optional($.typeargs)),
      field("arguments", alias($.signature_arguments, $.arguments)),
      optional(seq(":", field("return_type", $.return_type))),
    ),

    function_body: $ => seq(
      repeat($._statement),
      "end"
    ),

    record_entry: $ => choice(
      seq(
        field("key", $.identifier),
        ":", field("type", $._type)
      ),
      seq(
        "[", field("string_key", $.string), "]",
        ":", field("type", $._type)
      ),
      // TODO: there has to be a way around doing this, but I can't figure it out
      ...[ "type", "record", "enum", "userdata", "metamethod" ].map((reserved_id) => seq(
        field("key", alias(reserved_id, $.identifier)),
        ":", field("type", $._type)
      )),
      seq(
        "type", field("key", $.identifier), "=", field("value", choice($._type, $._newtype))
      ),
      seq(
        "record",
        field("key", $.identifier),
        field("typeargs", optional($.typeargs)),
        field("value", $.record_body),
      ),
      seq(
        "enum", field("key", $.identifier),
        field("value", $.enum_body),
      ),
    ),

    metamethod_annotation: $ => seq(
      "metamethod", field("name", $.identifier), ":", field("type", $._type)
    ),

    record_body: $ => seq(
      optional(seq("{", alias($._type, $.record_array_type), "}")),
      repeat(choice(
        $.record_entry,
        alias("userdata", $.userdata),
        field("metamethod", alias($.metamethod_annotation, $.metamethod)),
      )),
      "end"
    ),

    _record_def: $ => seq(
      "record",
      field("name", $.identifier),
      field("typeargs", optional($.typeargs)),
      field("record_body", $.record_body)
    ),

    record_declaration: $ => seq(
      $.scope,
      $._record_def,
    ),

    enum_body: $ => seq(
      repeat($.string),
      "end"
    ),

    _enum_def: $ => seq(
      "enum",
      field("name", $.identifier),
      $.enum_body
    ),

    enum_declaration: $ => seq(
      $.scope,
      $._enum_def
    ),

    // TODO: this node is kinda useless
    anon_record: $ => seq(
      "record",
      optional($.typeargs),
      field("record_body", $.record_body)
    ),

    _anon_enum: $ => seq(
      "enum",
      $.enum_body
    ),

    _newtype: $ => choice(
      $._anon_enum,
      $.anon_record,
    ),

    type_annotation: $ => seq(
      ":",
      list($._type)
    ),

    _type: $ => prec(2, choice(
      $.simple_type,
      $.type_index,
      $.table_type,
      $.function_type,
      $.type_union,
      seq("(", $._type, ")")
    )),

    typearg_params: $ => prec.right(1000, seq(
      "<", list($._type), ">"
    )),

    type_index: $ => prec.right(prec_type_op.index, seq(
      choice($.identifier, $.type_index), ".", $.identifier,
      optional(alias($.typearg_params, $.typeargs))
    )),

    simple_type: $ => prec.right(1000, seq(
      field("name", $.identifier),
      optional(alias($.typearg_params, $.typeargs))
    )),

    table_type: $ => seq(
      "{",
      choice(
        field("value_type", $._type),
        seq(
          field("key_type", $._type),
          ":",
          field("value_type", $._type),
        ),
        seq(
          field("tuple_type", $._type),
          repeat1(seq(",", field("tuple_type", $._type)))
        )
      ),
      "}"
    ),

    function_type_args: $ => seq(
      "(",
      optional(choice(
        seq(
          $._partypelist,
          optional(seq(",", alias($._annotated_var_arg, $.varargs)))
        ),
        alias($._annotated_var_arg, $.varargs)
      )),
      ")",
    ),

    function_type: $ => prec.right(1, seq(
      "function",
      field("typeargs", optional($.typeargs)),
      optional(seq(
        field("arguments", alias($.function_type_args, $.arguments)),
        optional(seq(
          ":",
          field("return_type", $.return_type)
        ))
      ))
    )),

    goto: $ => seq("goto", $.identifier),

    index: $ => seq(
      $._prefix_expression,
      choice(
        field("key", seq(".", $.identifier)),
        field("expr_key", seq("[", $._expression, "]"))
      )
    ),

    _var: $ => prec(1, choice(
      $.identifier,
      $.index,
    )),

    varargs: $ => "...",
    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    number: $ => choice(
      /\d+(\.\d+)?(e\d+)?/i,
      /\.\d+(e\d+)?/i,
      /0x[0-9a-fA-F]+(\.[0-9a-fA-F]+)?(p\d+)?/,
    ),
    boolean: $ => choice("true", "false"),

    _short_string_content: $ => alias(repeat1(choice(
          $.format_specifier,
          $.escape_sequence,
          token.immediate(prec(1, '%')),
          prec(0, $._short_string_char),
        )), $.string_content),

    _long_string_content: $ => alias(repeat1(choice(
          $.format_specifier,
          $._long_string_char,
          token.immediate(prec(1, '%')),
        )), $.string_content),

    string: $ => prec(2, choice(
      seq(
        field("start", alias($._short_string_start, "short_string_start")),
        field("content", optional($._short_string_content)),
        field("end", alias($._short_string_end, "short_string_end")),
      ),

      seq(
        field("start", alias($._long_string_start, "long_string_start")),
        field("content", optional($._long_string_content)),
        field("end", alias($._long_string_end, "long_string_end")),
      ),
    )),

    format_specifier: $ => token.immediate(prec(3, seq(
      '%',
      choice(
        '%',
        seq(
          optional(choice(
            '+', '-'
          )),
          optional(' '),
          optional('#'),
          optional(/[0-9]+/),
          optional('.'),
          optional(/[0-9]+/),
          /[AaEefGgcdiouXxpqs]/,
        ),
      )
    ))),

    escape_sequence: $ => token.immediate(prec(3, seq(
      '\\',
      choice(
        /[abfnrtvz"'\\]/,
        seq('x', /[0-9a-fA-F]{2}/),
        seq('d', /[0-7]{3}/),
        seq("u{", /[0-9a-fA-F]{1,8}/, '}'),
      ),
    ))),

    nil: $ => "nil",
  }
})

