
const list = (item) => seq(item, repeat(seq(",", item)))
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
}

module.exports = grammar({
  name: 'Teal',

  conflicts: $ => [
    [$.table_constructor],
    [$.type_annotation, $._type],
    [$.type_annotation],
    [$._type],
    [$.function_type],
    [$.retstat],
    [$._parnamelist],
    [$._expression, $._var],
  ],

  rules: {
    program: $ => repeat($._statement),
    _statement: $ => choice(
      $.var_declaration,
      $.retstat,
      $.for_statement,
      $.do_statement,
      $.while_statement,
      $.repeat_statement,
      $.function_call,
      $.function_statement,
      $.if_statement
    ),

    retstat: $ => seq('return', optional(list($._expression))),

    if_statement: $ => seq(
      "if", $._expression, "then",
      repeat($._statement),
      repeat($.elseif_block),
      optional($.else_block),
      "end"
    ),

    elseif_block: $ => seq("elseif", $._expression, "then", repeat($._statement)),
    else_block: $ => seq("else", repeat($._statement)),

    for_statement: $ => choice(
      seq(
        "for", $.identifier, "=", $._expression, ",", $._expression, optional(seq(",", $._expression)), $.do_statement
      ),
      seq(
        "for", list($.identifier), "in", list($._expression), $.do_statement
      )
    ),

    while_statement: $ => seq(
      "while", $._expression, $.do_statement
    ),

    repeat_statement: $ => seq(
      "repeat", repeat($._statement), "until", $._expression
    ),

    do_statement: $ => seq(
      "do",
      repeat($._statement),
      "end"
    ),

    _expression: $ => choice(
      $.identifier,
      $.number,
      $.string,
      $.table_constructor,
      $.functiondef,
      $.function_call,
      $.bin_op,
      $.unary_op
    ),

    unary_op: $ => prec.left(prec_op.unary, seq(
      choice('not', '#', '-', '~'),
      $._expression
    )),

    bin_op: $ => choice(
      ...[
        ['or', 'or', prec_op.or],
        ['and', 'and', prec_op.and],
        ['lt', '<', prec_op.comp],
        ['le', '<=', prec_op.comp],
        ['eq', '==', prec_op.comp],
        ['ne', '~=', prec_op.comp],
        ['ge', '>=', prec_op.comp],
        ['gt', '>', prec_op.comp],
        ['bor', '|', prec_op.bor],
        ['bnot', '~', prec_op.bnot],
        ['band', '&', prec_op.band],
        ['bls', '<<', prec_op.bshift],
        ['brs', '>>', prec_op.bshift],
        ['add', '+', prec_op.plus],
        ['sub', '-', prec_op.plus],
        ['mul', '*', prec_op.mult],
        ['div', '/', prec_op.mult],
        ['idiv', '//', prec_op.mult],
        ['mod', '%', prec_op.mult],
      ].map(([name, operator, precedence]) => prec.left(precedence, seq(
        $._expression,
        field(name + '_op', operator),
        $._expression
      ))),
      ...[
        ['concat', '..', prec_op.concat],
        ['pow', '^', prec_op.power],
      ].map(([name, operator, precedence]) => prec.right(precedence, seq(
        $._expression,
        field(name + '_op', operator),
        $._expression
      ))),
      ...[
        ['is', prec_op.is],
        ['as', prec_op.as]
      ].map(([operator, precedence]) => prec.right(precedence, seq(
        $._expression,
        field(operator + '_op', operator),
        $._type
      )))
    ),

    var_declaration: $ => seq(
      choice("local", "global"),
      $.identifier,
      repeat(seq(
        ",",
        $.identifier
      )),
      optional($.type_annotation),
      optional(seq("=", list($._expression)))
    ),

    _prefix_expression: $ => prec(10, choice(
      $._var,
      $.function_call,
      seq("(", $._expression, ")")
    )),
    function_call: $ => prec(10, seq(
      alias(seq(
        $._prefix_expression,
        optional(seq(":", $.identifier))
      ), $.called_object),
      choice(
        seq("(", optional(list($._expression)), ")"),
        $.string,
        $.table_constructor
      )
    )),

    table_constructor: $ => seq(
      "{",
      repeat(
        choice(
          seq(
            $._expression,
            repeat(seq(
              choice(";", ","),
              $._expression
            )),
            optional(choice(";", ","))
          ),
          seq(
            field("table_key", $.identifier),
            "=",
            $._expression,
            optional(choice(";", ","))
          ),
          seq(
            "[", field("table_expr_key", $._expression), "]",
            "=",
            $._expression,
            optional(choice(";", ","))
          )
        )
      ),
      "}"
    ),

    function_statement: $ => seq(
      choice("local", "global"),
      "function",
      alias($.identifier, $.function_name),
      $._funcbody
    ),

    _retlist: $ => choice(
      seq(
        "(",
        optional(list($._type)),
        optional("..."),
        ")"
      ),
      seq(
        list($._type),
        optional("...")
      )
    ),
    _parlist: $ => choice(
      seq(
        $._parnamelist,
        optional(seq(
          ",", "...",
          optional(seq(":", $._type))
        ))
      ),
      seq(
        "...",
        optional(seq(":", $._type))
      )
    ),
    _partypelist: $ => list($._partype),
    _partype: $ => seq(optional(seq(alias($.identifier, "arg_name"), ":")), $._type),
    _parnamelist: $ => list($._parname),
    _parname: $ => seq(alias($.identifier, $.arg_name), optional(seq(":", $._type))),
    _typeargs: $ => seq("<", list(alias($.identifier, $.typearg)), ">"),
    functiondef: $ => seq(
      "function",
      $._funcbody
    ),
    _funcbody: $ => seq(
      optional($._typeargs),
      "(",
      optional($._parlist),
      ")",
      optional(seq(":", $._retlist)),
      repeat($._statement),
      "end"
    ),

    type_annotation: $ => seq(
      ":",
      // optional("("), //TODO: how to do optional pairs?
      list($._type)
      // optional(")")
    ),

    _type: $ => seq(
      choice(
        $.simple_type,
        $.table_type,
        $.function_type
      ),
      repeat(seq(
        "|", choice($.simple_type, $.table_type, $.function_type)
      ))
    ),

    simple_type: $ => alias(seq(
      $.identifier, repeat(seq(".", $.identifier)),
    ), 'simple_type'),

    table_type: $ => choice(
      seq( // array
        "{",
        field('value_type', $._type),
        "}"
      ),
      seq( // map
        "{",
        field('key_type', $._type),
        ":",
        field('value_type', $._type),
        "}"
      )
    ),

    function_type: $ => seq(
      "function",
      // TODO: generics
      "(",
      optional(list(field("arg_type", $._type))), // TODO: named args in types: foo: function(a: string, b: number)
      ")",
      optional(seq(
        ":",
        list(field("ret_type", $._type))
      ))
    ),

    _var: $ => choice(
      $.identifier,
      seq(
        $._prefix_expression,
        choice(
          seq("[", $._expression, "]"),
          seq(".", $.identifier)
        )
      ),
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    number: $ => /\d+/, //TODO: hex and stuff
    string: $ => /"[^"]*"/, //TODO: [==[multiline strings]==] externally, 'single quote strings'
    boolean: $ => choice("true", "false"),
    nil: $ => "nil"

  }
})

// vim: sw=2:ts=2:set expandtab:
