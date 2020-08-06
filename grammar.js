
const list = (item) => seq(item, repeat(seq(",", item)))

module.exports = grammar({
  name: 'Teal',

  conflicts: $ => [
    [$.table_constructor],
    [$.type_annotation, $._type],
    [$.type_annotation],
    [$._type],
    [$.function_type]
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

    simple_type: $ => seq(
      $.identifier, repeat(seq(".", $.identifier)),
    ),

    table_type: $ => seq(
      "{",
      $._type, //array
      optional(seq(":", $._type)), //map
      "}"
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

    identifier: $ => /[a-zA-Z_][a-zA-Z_0-9]*/,
    number: $ => /\d+/, //TODO: hex and stuff
    string: $ => /"[^"]*"/ //TODO: [==[multiline strings]==] externally, 'single quote strings'

  }
})
