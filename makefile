check:
	valgrind --leak-check=full --show-leak-kinds=all  --log-file=checked --track-origins=yes --dsymutil=yes --keep-stacktraces=alloc ./myexec

build:
	gcc  -std=c11 -Wall -ggdb3  -o0 -o myexec ./string.c