#include "../include/tree.h"
#include "../include/parser.h"

int skip_line()
{
  int i = 0;
  do
  {
    char *token = take_tok();
    if (strcmp(token, "\n") == 0)
    {
      valid_tok();
      i ++;
    }
    else
      return i;
  }while (1);

  return i;
}

int check_token_p()
{
  char *token = take_tok();

  if (token 
      && (strcmp(token, "&&") == 0 || strcmp(token, "||") == 0 
        || strcmp(token, ";") == 0 || strcmp(token, "&") == 0
        || strcmp(token, "if") == 0 || strcmp(token, "then") == 0
        || strcmp(token, "|") == 0))
    return 1;
  return 0;
}


struct ntree *input_parser()
{
  struct ntree *ntree = list_p();
  return ntree;
}
