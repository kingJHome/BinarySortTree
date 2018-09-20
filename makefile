test: test.c bstTree.c
	gcc -o $@ $^

testdebugger: test.c bstTree.c
	gcc -g $^ -o $@
