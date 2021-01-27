
parser.so: src/parser.c src/scanner.c
	$(CC) -fPIC -shared src/parser.c src/scanner.c -o parser.so

all: test parser.so

src/parser.c: grammar.js
	tree-sitter generate

test: parser.so
	tree-sitter test

.PHONY: test

