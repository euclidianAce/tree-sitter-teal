{
  "targets": [
    {
      "target_name": "tree_sitter_teal_binding",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "src"
      ],
      "sources": [
        "src/binding.cc",
        "src/parser.c",
        "src/scanner.c",
      ],
      "cflags_c": [
        "-std=c99",
      ]
    }
  ]
}
