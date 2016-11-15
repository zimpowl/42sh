#ifndef TREE_H
#define TREE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct btree
{
  struct btree *left;
  struct btree *right;
  char *name;
  char *value;
};

enum token_parser
{
  LIST,
  AND_OR,
  PIPELINE,
  GROUP,
  FUNCTION,
  REDIRECTION,
  WORD,
  ASSIGNMENT_WORD,
  NAME,
  NEWLINE,
  IO_NUMBER,
  OPERATOR,
  RESERVED_WORD,
  COMMAND
};

struct ntree
{
  char *name;
  enum token_parser token;
  struct ntree **sons;
  unsigned size;
};

struct btree *add_btree(struct btree *tree, char *name);
struct btree *search_btree(struct btree * tree, char *value);
struct btree *delete_btree(struct btree *tree, char *value);
void print_btree(struct btree *tree);

struct ntree *new_lift(char *word);
struct ntree *new_ntree(char *word, enum token_parser token);
struct ntree *add_ntree(struct ntree *tree, struct ntree *son);
void my_print_ntree(struct ntree *ntree);
void print_ntree(struct ntree *tree);
int fakefunction(char *name);
int exec_all(struct ntree *tree);

#endif
