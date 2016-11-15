all:
	gcc -Wall -Werror -Wextra -std=c99 -pedantic btree.c -o ntree
	./ntree

exec:
	gcc -Wall -Werror -Wextra -std=c99 -pedantic executor.c -o executor

pipe:
	gcc -Wall -Werror -Wextra -std=c99 -pedantic pipe.c -o pipe
	./pipe

gdb:
	gcc -Wall -Werror -Wextra -std=c99 -pedantic -g btree.c -o todebug
	gdb --tui -q ./todebug

clean:
	$(RM) todebug executor ntree

.PHONY: exec all gdb clean pipe
