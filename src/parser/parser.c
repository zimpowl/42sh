#include "../include/tree.h"
#include "../include/parser.h"

char *my_argv[10];
int pos;

void init_tok(char *argv[], int len)
{
  pos = 0;
  for (int i = 0; i < len; i++)
    my_argv[i] = argv[i];
}

char* take_tok()
{
  if (!my_argv[pos])
    return NULL;
  char* token = my_argv[pos];
  return token;
}

char* take_next_tok()
{
  if (!my_argv[pos + 1])
    return NULL;
  char* token = my_argv[pos + 1];
  return token;
}

void valid_tok()
{
  pos ++;
}

struct ntree* example()
{
  struct ntree *parsing = new_ntree("begin", WORD);
  struct ntree *test = new_ntree(";", WORD);
  struct ntree *test2 = new_ntree("&", WORD);
  struct ntree *left = new_ntree("ls", WORD);
  struct ntree *right = new_ntree("cd", WORD);
  add_ntree(parsing, test);
  add_ntree(parsing, test2);
  
  add_ntree(test, left);
  add_ntree(test, right);
  
  add_ntree(test2, left);
  add_ntree(test2, right);
  return parsing;
}

int main()
{
  char *str[4] = { "ls", "&&", "ca" , "Makefile"};
  init_tok(str, 4);
  
  //struct ntree *test = example();
  //my_print_ntree(test);
  
  struct ntree *tree = input_parser();
  read_p(tree);
  my_print_ntree(tree);
  return 0;
}
