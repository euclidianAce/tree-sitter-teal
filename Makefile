
all: test parser

gen: grammar.js
	./node_modules/tree-sitter-cli/tree-sitter generate

test: gen
	./node_modules/tree-sitter-cli/tree-sitter test

parser: src/parser.c src/scanner.c
	gcc -fPIC -shared src/parser.c src/scanner.c -o parser.so

.PHONY: test

