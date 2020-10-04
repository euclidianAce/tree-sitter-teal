
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
}

module.exports = grammar({
  name: 'teal',

  conflicts: $ => [
    [$._retlist],
    [$._parnamelist],
    [$._partypelist],
  ],

  extras: $ => [
    $.comment,
    /[\s\n]/
  ],

  externals: $ => [
    $.comment,
    $.string
  ],

  word: $ => $.identifier,

  rules: {
    program: $ => repeat($._statement),
    _statement: $ => prec(1, choice(
      $.var_declaration,
      $.var_assignment,
      $.type_declaration,
      $.record_declaration,
      $.enum_declaration,
      $.retstat,
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
    )),

    retstat: $ => prec.right(1, seq('return', optional(list($._expression)))),
    break: $ => 'break',

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
        "for", $.identifier, "=", $._expression, ",", $._expression, optional(seq(",", $._expression)), alias($.do_statement, $.for_body)
      ),
      seq(
        "for", list($.identifier), "in", list($._expression), alias($.do_statement, $.for_body)
      )
    ),

    while_statement: $ => seq(
      "while", $._expression, alias($.do_statement, $.while_body)
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
      $._var,
      $.number,
      $.string,
      $.boolean,
      $.nil,
      $.table_constructor,
      $.functiondef,
      $.function_call,
      $._prefix_expression,
      $.bin_op,
      $.unary_op,
      alias("...", $.varargs)
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

    var_declarator: $ => choice(
      seq($.identifier, "<", alias($.identifier, $.attribute), ">"),
      $.identifier,
    ),

    var_declaration: $ => seq(
      choice("local", "global"),
      list(alias($.var_declarator, $.var)),
      optional($.type_annotation),
      optional(seq("=", list($._expression)))
    ),

    type_declaration: $ => choice(
      seq(
        choice("local", "global"),
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
    arguments: $ => choice(
      seq("(", optional(list($._expression)), ")"),
      $.string,
      $.table_constructor
    ),
    function_call: $ => prec(10, seq(
      seq(
        $._prefix_expression,
        optional(seq(":", $.identifier))
      ),
      $.arguments
    )),

    _table_field: $ => prec(2, choice(
      seq("[", alias($._expression, $.table_key), "]", "=", alias($._expression, $.table_value)),
      seq(
        alias($.identifier, $.table_key),
        optional(seq(":", $._type)),
        "=",
        alias($._expression, $.table_value)
      ),
      alias($._expression, $.table_value)
    )),
    table_constructor: $ => seq(
      "{",
      optional(list($._table_field, choice(",", ";"))),
      optional(choice(",", ";")),
      "}"
    ),

    function_name: $ => seq(
      alias($.identifier, $.base),
      choice(
        seq(
          repeat(seq(".", alias($.identifier, $.entry))),
          seq(":", alias($.identifier, $.method))
        ),
        repeat1(seq(".", alias($.identifier, $.entry)))
      )
    ),
    function_statement: $ => choice(
      prec(100, seq(
        choice("local", "global"),
        "function",
        alias($.identifier, $.function_name),
        $._funcbody
      )),
      seq(
        "function",
        $.function_name,
        $._funcbody
      )
    ),

    _retlist: $ => choice(
      seq(
        "(",
        optional(list($._type)),
        optional(alias("...", $.vararg)),
        ")"
      ),
      seq(
        list($._type),
        optional(alias("...", $.vararg)),
      )
    ),
    _parlist: $ => choice(
      seq(
        $._parnamelist,
        optional(seq(
          ",", alias("...", $.varargs),
          optional(seq(":", $._type))
        ))
      ),
      seq(
        alias("...", $.varargs),
        optional(seq(":", $._type))
      )
    ),

    _partypelist: $ => list($._partype),
    _partype: $ => seq(optional(seq(alias($.identifier, $.arg_name), ":")), $._type),
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
      optional(seq(":", alias($._retlist, $.ret))),
      repeat($._statement),
      "end"
    ),

    _record_body: $ => seq(
      optional($._typeargs),
      optional(seq("{", alias($._type, $.record_array_type), "}")),
      repeat(choice(
        seq("type", alias($.identifier, $.record_type), "=", $._newtype),

        // TODO: there's gotta be a way around this, but precedence doesn't seem to work
        seq(alias("type", $.record_entry), ":", $._type),
        seq(alias("enum", $.record_entry), ":", $._type),
        seq(alias("record", $.record_entry), ":", $._type),
        seq(alias($.identifier, $.record_entry), ":", $._type),
        alias($._record_def, $.record_block),
        alias($._enum_def, $.enum_block)
      )),
      "end"
    ),

    _record_def: $ => seq(
      "record",
      alias($.identifier, $.record_name),
      $._record_body
    ),

    record_declaration: $ => seq(
      choice("local", "global"),
      $._record_def
    ),

    _enum_body: $ => seq(
      repeat($.string),
      "end"
    ),

    _enum_def: $ => seq(
      "enum",
      alias($.identifier, $.enum_name),
      $._enum_body
    ),

    enum_declaration: $ => seq(
      choice("local", "global"),
      $._enum_def
    ),

    _newtype: $ => choice(
      seq("enum", alias($._enum_body, $.enum_block)),
      seq("record", alias($._record_body, $.record_block))
    ),

    type_annotation: $ => seq(
      ":",
      list($._type)
    ),

    _type: $ => prec.right(1, seq(
      choice(
        $.simple_type,
        $.table_type,
        $.function_type
      ),
      repeat(seq(
        "|", choice($.simple_type, $.table_type, $.function_type)
      ))
    )),

    simple_type: $ => prec.left(1, alias(seq(
      $.identifier, repeat(seq(".", $.identifier)),
      optional($._typeargs)
    ), 'simple_type')),

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

    function_type: $ => prec.right(1, seq(
      "function",
      optional($._typeargs),
      "(",
      choice(
        seq(
          optional(alias($._partypelist, $.arg)),
          alias(optional(
            seq(
              alias(",", "comma"),
              alias(seq("...", ":"), "vararg_annotation"),
              $._type
            )
          ), $.vararg),
        ),
        seq(
          alias(optional(
            seq(
              alias(seq("...", ":"), "vararg_annotation"),
              $._type
            )
          ), $.vararg)
        )
      ),
      ")",
      optional(seq(
        ":",
        alias($._retlist, $.ret)
      ))
    )),

    goto: $ => seq("goto", $.identifier),

    _var: $ => prec(1, choice(
      $.identifier,
      seq(
        $._prefix_expression,
        choice(
          seq("[", $._expression, "]"),
          seq(".", $.identifier)
        )
      ),
    )),

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    number: $ => choice(
      /\d+(\.\d+)?(e\d+)?/i,
      /0x[0-9a-f]+(\.[0-9a-f]+)?/i,
    ),
    boolean: $ => choice("true", "false"),
    nil: $ => "nil"

  }
})

// vim: sw=2:ts=2:set expandtab:
