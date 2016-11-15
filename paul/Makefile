CC = gcc
CFLAGS = -g -std=c99 -pedantic -Werror -Wextra -Wall -pthread

EXEC= parser

SRC= 		 ../src/tree/ntree.c \
				 ../src/parser/input_parser.c \
				 ../src/parser/list_parser.c \
				 ../src/parser/and_or_parser.c \
				 ../src/parser/pipeline_parser.c \
				 ../src/parser/command_parser.c \
				 ../src/parser/shellcom_parser.c \
				 ../src/parser/rules_parser.c \
				 ../src/parser/func_parser.c \
				 ../src/parser/redir_parser.c \
				 ../src/parser/read_parser.c \
				 ../src/executor.c \
				 ../src/parser/parser.c

OBJS= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC):
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm $(OBJS) $(EXEC)
