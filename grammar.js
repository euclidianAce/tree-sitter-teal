module.exports = grammar({
  name: 'Teal',

  conflicts: $ => [
    [$.table_constructor]
  ],

  rules: {
    program: $ => repeat($._statement),
    _statement: $ => choice(
      $.local_declaration,
      $.global_declaration,
    ),

    _expression: $ => choice(
      $.identifier,
      $.number,
      $.string,
      $.table_constructor
    ),

    local_declaration: $ => seq(
      "local",
      $.identifier,
      repeat(seq(
        ",",
        $.identifier
      )),
      "=",
      $._expression,
      repeat(seq(
        ",",
        $._expression
      ))
    ),

    global_declaration: $ => seq(
      "global",
      $.identifier,
      repeat(seq(
        ",",
        $.identifier
      )),
      "=",
      $._expression,
      repeat(seq(
        ",",
        $._expression
      ))
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

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    number: $ => /\d+/, //TODO: hex and stuff
    string: $ => /"[^"]*"/ //TODO: multiline strings

  }
})
