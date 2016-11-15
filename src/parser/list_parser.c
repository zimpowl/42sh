#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *list_p()
{
  struct ntree *new = and_or_p();
  if (!new)
    return NULL;

  char *token = take_tok();

  while (token && (strcmp(token, ";") == 0
      || strcmp(token, "&") == 0))
  {
    valid_tok();
    struct ntree *new_sep = new_ntree(token, LIST);
    new_sep = add_ntree(new_sep, new);
    new_sep = add_ntree(new_sep, and_or_p());

    new = new_sep;
    token = take_tok();
  }
  return new;
}

struct ntree *compound_list_p()
{
  skip_line();

  struct ntree *new = and_or_p();
  if (!new)
    return NULL;
  
  char *token = take_tok();

  while (token && (strcmp(token, ";") == 0 
          || strcmp(token, "&") == 0
          || skip_line()))
  {
    valid_tok();
    struct ntree *new_sep = new_ntree(token, LIST);
    new_sep = add_ntree(new_sep, new);
    new_sep = add_ntree(new_sep, and_or_p());

    new = new_sep;
    token = take_tok();
  }

  return new;
}

struct ntree *do_group_p()
{
  char *token = take_tok();
  
  if (!token || strcmp(token, "do") != 0)
    return NULL;

  valid_tok();
  struct ntree *ntree = new_ntree(token, GROUP);
  struct ntree *new = compound_list_p();
  if (!new)
    return NULL;

  ntree = add_ntree(ntree, new);

  token = take_tok();
  if (!token || strcmp(token, "done") != 0)
    return NULL;

  new = new_ntree(token, GROUP);
  ntree = add_ntree(ntree, new);

  return ntree;
}



