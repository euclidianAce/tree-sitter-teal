#!/usr/bin/env bash

make test && ./node_modules/tree-sitter-cli/tree-sitter parse ~/dev/tl/tl.tl > /tmp/tl_parsed.txt
echo "parsing tl.tl:"
res=$(tail /tmp/tl_parsed.txt | grep ERROR)
if [ -z "$res" ]; then
	echo -e "\e[32;1m    No errors found parsing tl.tl\e[0m";
else
	echo -e "\e[31;1m    Errors parsing tl.tl";
	echo -e "    See /tmp/tl_parsed.txt for more info\n";
	echo "    $res";
fi
echo -e "\e[0m";
