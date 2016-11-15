#include "../include/tree.h"
#include "../include/parser.h"


struct ntree *rule_if_p()
{
  char *token = take_tok();
  if (token && strcmp(token, "if") != 0)
    return NULL;

  struct ntree *ntree = new_ntree(token, RESERVED_WORD);
  valid_tok();
  
  struct ntree *new = compound_list_p();
  if (!new)
    return NULL;
  
  ntree = add_ntree(ntree, new);

  token = take_tok();
  if (!token || strcmp(token, "then") != 0)
    return NULL;


  new = new_ntree(token, RESERVED_WORD);
  ntree = add_ntree(ntree, new);
  valid_tok();

  new = compound_list_p();
  if (!new)
    return NULL;

  ntree = add_ntree(ntree, new);
  
  token = take_tok();
  if (!token || strcmp(token, "fi") != 0)
    return NULL;

  new = new_ntree(token, RESERVED_WORD);
  ntree = add_ntree(ntree, new);
  valid_tok();

  return ntree;
}

/*struct ntree *rule_for_p()
{
  char *token = take_tok();

  if (strcmp(token, "for") != 0)
    return NULL;

  struct ntree *ntree = new_ntree(token, "operator");
  valid_tok();
  token = take_tok();

  if (!token)
    return NULL;

  struct ntree *new = new_ntree(token, "WORD");
  valid_tok();
  token = take_token();
  
  if (token && (strcmp(token, ";") == 0 || skip_line()))
  {
    struct ntree *new_sp
  }
   
}*/
