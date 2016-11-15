#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *pipeline_p()
{
  struct ntree *ntree = NULL;

  char *token = take_tok();
  if (token && strcmp(token, "!") == 0)
  {
    struct ntree *new_sep = new_ntree(token, PIPELINE);
    ntree = add_ntree(ntree, new_sep); 
    valid_tok();
  }
  
  struct ntree *new = command_p();
  if (!new)
    return NULL;

  token = take_tok();

  while (token && strcmp(token, "|") == 0)
  {
    valid_tok();
    struct ntree *new_sep = new_ntree(token, PIPELINE);
    new_sep = add_ntree(new_sep, new);
    new = command_p();
    
    if (!new)
      return NULL;
    new_sep = add_ntree(new_sep, new);
    new = new_sep;
    token = take_tok();
  }

  ntree = add_ntree(ntree, new);
  return ntree;
}
