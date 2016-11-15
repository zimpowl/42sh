#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *and_or_p()
{
  struct ntree *new = pipeline_p();
  if (!new)
    return NULL;

  char *token = take_tok();

  while (token && (strcmp(token, "&&") == 0 || strcmp(token, "||") == 0))
  {
    valid_tok();
    struct ntree *new_sep = new_ntree(token, AND_OR);
    new_sep = add_ntree(new_sep, new);
    new = pipeline_p();
    if (!new)
      return NULL;
    new_sep = add_ntree(new_sep, new);
    new = new_sep;
    token = take_tok();
  }

  return new;
}
