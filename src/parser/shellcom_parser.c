#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *shell_command_p()
{
  struct ntree *new = rule_if_p();
  if (new)
    return new;
  
  /*return NULL;
  new = rule_for_p();
  if (new)
    return new;

  new = rule_while_p();
  if (new)
    return new;

  new = rule_until_p();
  if (new)
    return new;

  new = rule_case_p();
  if (new)
    return new;*/

  new = shell_commandbis_p();
  return new;
}

struct ntree *shell_commandbis_p()
{
  struct ntree *new = NULL;
  char *token = take_tok();
  if (strcmp(token, "{") == 0 || strcmp(token, ")") == 0)
  {
    valid_tok();
    new = compound_list_p();
    if (!new)
      return NULL;

    token = take_tok();
    if (strcmp(token, "}") != 0 && strcmp(token, ")") != 0)
      return NULL;
    valid_tok();
  }
  return new;
}
