
;; Basic statements/Keywords
[ "if" "then" "elseif" "else" ] @keyword.conditional
[ "for" "while" "repeat" "until" ] @keyword.repeat
[ "in" "local" "return" (break) (goto) "do" "end" ] @keyword
(label) @label

;; Global isn't a real keyword, but it gets special treatment in these places
(var_declaration "global" @keyword)
(function_statement "global" @keyword)
(record_declaration "global" @keyword)
(enum_declaration "global" @keyword)

;; Ops
[ "not" "and" "or" "as" "is" ] @keyword.operator

[ "=" "~=" "==" "<=" ">=" "<" ">"
"+" "-" "%" "/" "//" "*" "^"
"&" "~" "|" ">>" "<<"
".." "#" ] @operator

;; function stuffs

(function_statement
  "function" @keyword.function
  name: (_) @function)
(anon_function
  "function" @keyword.function)
(function_body "end" @keyword.function)
(arg name: (identifier) @parameter)

(typeargs
  "<" @punctuation.bracket
  . (identifier) @parameter
  . ("," . (identifier) @parameter)*
  . ">" @punctuation.bracket)

(function_call
  (identifier) @function . (arguments))

;; type stuffs
(record_declaration
  "record" @keyword)
(record_block
  "record" @keyword)
(anon_record
  "record" @keyword)
(record_body
  "end" @keyword)
(record_body
  "type" @keyword . (record_type) @type . "=")

(enum_declaration [ "enum" "end" ] @keyword)
(enum_block [ "enum" "end" ] @keyword)
(type_declaration "type" @keyword)
(type_declaration (type_name) @type)
(simple_type) @type
(function_type "function" @type)

(record_name) @type
(enum_name) @type

;; The rest of it

(var_declaration
  (var
    "<" @punctuation.bracket
    . (attribute) @keyword
    . ">" @punctuation.bracket))
[ "(" ")" "[" "]" "{" "}" ] @punctuation.bracket
(boolean) @boolean
(comment) @comment
(identifier) @variable
(nil) @constant.builtin
(number) @number
(string) @string
(table_constructor ["{" "}"] @constructor)
(varargs) @constant.builtin
"," @punctuation.delimiter

(ERROR) @error
