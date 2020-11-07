
all: test parser.so

src/parser.c: grammar.js
	./node_modules/tree-sitter-cli/tree-sitter generate

test: parser.so
	./node_modules/tree-sitter-cli/tree-sitter test

parser.so: src/parser.c src/scanner.c
	gcc -fPIC -shared src/parser.c src/scanner.c -o parser.so

.PHONY: test

