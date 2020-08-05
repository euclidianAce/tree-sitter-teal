
let list = (item) => seq(item, repeat(seq(",", item)))

module.exports = grammar({
  name: 'Teal',

  conflicts: $ => [
    [$.table_constructor],
    [$.type_annotation, $._type],
  ],

  rules: {
    program: $ => repeat($._statement),
    _statement: $ => choice(
      $.var_declaration,
      $.function_declaration,
      $.retstat
    ),

    retstat: $ => seq('return', optional(list($._expression))),

    _expression: $ => choice(
      $.identifier,
      $.number,
      $.string,
      $.table_constructor,
      $.anon_function
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

    function_declaration: $ => seq(
      choice("local", "global"),
      "function",
      field("function_name", $.identifier),
      "(",
      optional(seq(
        field("arg", $.identifier),
        repeat(seq(",", $.identifier))
      )),
      ")",
      repeat($._statement),
      "end"
    ),

    anon_function: $ => seq(
      "function",
      "(",
      optional(seq(
        field("arg", $.identifier),
        repeat(seq(",", $.identifier))
      )),
      ")",
      repeat($._statement),
      "end"
    ),

    type_annotation: $ => seq(
      ":",
      // optional("("), //TODO: how to do optional pairs?
      list($._type)
      // optional(")")
    ),

    _type: $ => choice(
      $.simple_type,
      $.table_type
    ),

    simple_type: $ => seq(
      $.identifier, repeat(seq(".", $.identifier)),
    ),

    table_type: $ => choice(
      seq(
        "{",
        $._type, //array
        optional(seq(":", $._type)), //map
        "}"
      )
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    number: $ => /\d+/, //TODO: hex and stuff
    string: $ => /"[^"]*"/ //TODO: [==[multiline strings]==] externally, 'single quote strings'

  }
})
