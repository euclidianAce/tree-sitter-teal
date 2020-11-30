
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

module.exports = grammar({
  name: 'teal',

  extras: $ => [
    $.comment,
    /[\s\n]/,
  ],

  externals: $ => [
    $.comment,
    $.string,
  ],

  inline: $ => [
    $.scope,
    $._partypelist,
    $._parnamelist,
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
      $.varargs
    ),

    unary_op: $ => prec.left(prec_op.unary, seq(
      choice('not', '#', '-', '~'),
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
        field('op', operator),
        $._expression
      ))),
      ...[
        ['..', prec_op.concat],
        ['^', prec_op.power],
      ].map(([operator, precedence]) => prec.right(precedence, seq(
        $._expression,
        field('op', operator),
        $._expression
      ))),
      ...[
        ['is', prec_op.is],
        ['as', prec_op.as]
      ].map(([operator, precedence]) => prec.right(precedence, seq(
        $._expression,
        field('op', operator),
        $._type
      ))),
      prec.right(prec_op.is, seq(
        $._expression,
        field('op', "is"),
        $._type
      )),
      prec.right(prec_op.as, seq(
        $._expression,
        field('op', "as"),
        choice($._type, $.type_tuple)
      ))
    ),

    type_tuple: $ => seq("(", list($._type), ")"),
    type_union: $ => prec.left(1, seq($._type, "|", $._type)),

    var_declarator: $ => seq(
      field("name", $.identifier),
      optional(seq("<", field("attribute", alias($.identifier, $.attribute)), ">")),
    ),

    var_declaration: $ => seq(
      $.scope,
      list(alias($.var_declarator, $.var)),
      optional($.type_annotation),
      optional(seq("=", list($._expression)))
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
      seq(
        choice($.record_declaration, $.enum_declaration)
      )
    ),

    var_assignment: $ => seq(
      list(alias($._var, $.var)), "=", list($._expression)
    ),

    _prefix_expression: $ => prec(10, choice(
      $._var,
      $.function_call,
      seq("(", $._expression, ")")
    )),
    method_index: $ => seq($._prefix_expression, ":", $.identifier),
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
      $.arguments
    )),

    table_entry: $ => prec(5, choice(
      seq("[", field("expr_key", $._expression), "]", "=", field("value", $._expression)),
      seq(
        field("key", $.identifier),
        field("type", optional(seq(":", $._type))),
        "=",
        field("value", $._expression)
      ),
      field("value", $._expression)
    )),
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
        $.function_signature,
        $.function_body
      ),
      seq(
        "function",
        field("name", $.function_name),
        $.function_signature,
        $.function_body
      )
    ),

    variadic_type: $ => prec(1, seq($._type, "...")),
    _retlist: $ => prec.right(choice(
      list($._type),
      seq("(", optional(list($._type)), ")"),
      seq(list($._type), ",", $.variadic_type),
      $.variadic_type,
    )),

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
      $.function_signature,
      $.function_body
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
      optional($.typeargs),
      alias($.signature_arguments, $.arguments),
      optional(seq(":", alias($._retlist, $.return_type))),
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
          "[", field("key", $.string), "]",
          ":", field("type", $._type)
        ),
        // TODO: there has to be a way around doing this, but I can't figure it out
        ...[ "type", "record", "enum", ].map((reserved_id) => seq(
          field("key", alias(reserved_id, $.identifier)),
          ":", field("type", $._type)
        )),
        seq(
          "type", field("key", $.identifier), "=", field("value", choice($._type, $._newtype))
        ),
        seq(
          "record", field("key", $.identifier),
          field("value", $.record_body),
        ),
        seq(
          "enum", field("key", $.identifier),
          field("value", $.enum_body),
        ),
    ),

    record_body: $ => seq(
      optional(seq("{", alias($._type, $.record_array_type), "}")),
      repeat($.record_entry),
      "end"
    ),

    _record_def: $ => seq(
      "record",
      field("name", $.identifier),
      optional($.typeargs),
      $.record_body
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
      $.record_body
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

    _type: $ => choice(
      $.simple_type,
      $.type_index,
      $.table_type,
      $.function_type,
      $.type_union
    ),

    type_index: $ => prec.left(1, seq(
      choice($.identifier, $.type_index), ".", $.identifier,
      optional($.typeargs)
    )),

    simple_type: $ => prec.left(1, seq(
      alias($.identifier, "name"),
      optional($.typeargs)
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
      optional($.typeargs),
      optional(seq(
        alias($.function_type_args, $.arguments),
        optional(seq(
          ":",
          alias($._retlist, $.return_type)
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
      /0x[0-9a-fA-F]+(\.[0-9a-fA-F]+)?(p\d+)?/,
    ),
    boolean: $ => choice("true", "false"),
    nil: $ => "nil"

  }
})

