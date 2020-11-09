
;; Basic statements
(if_statement [ "if" "then" "end" ] @conditional)
(elseif_block [ "elseif" "then" ] @conditional)
(else_block [ "else" ] @conditional)

(do_statement [ "do" "end" ] @keyword)
(for_statement
  "for" @repeat
  (for_body [ "do" "end" ] @keyword))
(while_statement
  "while" @repeat
  (while_body [ "do" "end" ] @keyword))
(repeat_statement [ "repeat" "until" ] @repeat)

[ "in" "local" "return" (break) (goto) "do" "end" ] @keyword
(label) @label

;; Global isn't a real keyword, but it gets special treatment
(var_declaration "global" @keyword)
(function_statement "global" @keyword)

;; Ops
[ "not" "and" "or" "as" "is" ] @keyword.operator

[ "=" "~=" "==" "<=" ">=" "<" ">"
"+" "-" "%" "/" "//" "*" "^"
"&" "~" "|" ">>" "<<"
".." "#" ] @operator

;; function stuffs

(function_statement
  "function" @keyword.function)
(anon_function
  "function" @keyword.function)
(function_body "end" @keyword)
(function_name) @function
(arg_name) @parameter

(typeargs
  "<" @punctuation.bracket .
  (identifier) @parameter
  .
  ("," . (identifier) @parameter)*
  . ">" @punctuation.bracket)

(function_call
  (identifier) @function . (arguments))

;; type stuffs
(record_declaration
  "record" @keyword)
(record_block
  "record" @keyword)
(record_body "end" @keyword)

(enum_declaration [ "enum" "end" ] @keyword)
(enum_block [ "enum" "end" ] @keyword)
(type_declaration "type" @keyword)
(type_declaration (type_name) @type)
(simple_type) @type
(function_type "function" @type)

(record_name) @type
(enum_name) @type

;; The rest of it

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
