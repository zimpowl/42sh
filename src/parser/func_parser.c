#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *func_p()
{
  struct ntree *ntree = NULL;
  char *token = take_tok();

  if (token && strcmp(token, "function") == 0)
  {
    valid_tok();
    ntree = new_ntree(token, FUNCTION);
    token = take_tok();
  }

  char *token2 = take_next_tok();
  if (!token2 || strcmp(token2, "(") != 0)
    return NULL;

  struct ntree *new = new_ntree(token, WORD);
  ntree = add_ntree(ntree, new);
  valid_tok();
  token = take_tok();

  new = new_ntree(token, FUNCTION);
  ntree = add_ntree(ntree, new);
  valid_tok();
  token = take_tok();

  if (!token || strcmp(token, ")") != 0)
    return NULL;
  
  new = new_ntree(token, FUNCTION);
  ntree = add_ntree(ntree, new);
  
  skip_line();

  new = shell_command_p();
  if (!new)
    return NULL;

  ntree = add_ntree(ntree, new);
  return ntree;
}
