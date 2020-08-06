
gen: grammar.js
	./node_modules/tree-sitter-cli/tree-sitter generate

test: gen
	./node_modules/tree-sitter-cli/tree-sitter test

.PHONY: test

