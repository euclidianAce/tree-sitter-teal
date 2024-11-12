package tree_sitter_teal_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_teal "github.com/tree-sitter/tree-sitter-teal/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_teal.Language())
	if language == nil {
		t.Errorf("Error loading Teal grammar")
	}
}
