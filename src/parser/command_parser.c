#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *command_p()
{
  struct ntree *new = simple_command_p();
  
  if (new)
    return new;
  
 new = shell_command_p();

 if (!new)
  new = func_p();

 if (new)
 {
   struct ntree *new_sep = NULL;
   do
   {
    new_sep = redir_p();
    new = add_ntree(new, new_sep);
    new = new_sep;
   }while (new_sep);

 }
 return new;
}


struct ntree *simple_command_p()
{
  struct ntree *new = prefix_p();
  struct ntree *new_sep = NULL;
  
  if (new)
  {
    do
    {
      struct ntree *new_sep = prefix_p();
      new = add_ntree(new, new_sep);
    }while (new_sep);
  }

  do
  {
    new_sep = element_p();
    if (!new_sep)
      return new;
    new = add_ntree(new, new_sep);
  } while (new);

  return new;
}

struct ntree *prefix_p()
{
  struct ntree *ntree = NULL;
  char *token = take_tok();
  char *token2 = take_next_tok();

  if (token && token2 && strcmp(token2, "=") == 0)
  {
    ntree = new_ntree(token2, ASSIGNMENT_WORD);
    struct ntree *new = new_ntree(token, WORD);
    ntree = add_ntree(ntree, new);

    valid_tok();
    valid_tok();
    token = take_tok();
    if (!token)
      return NULL;

    new = new_ntree(token, WORD);
    ntree = add_ntree(ntree, new);
  }
  
  return ntree;
}

struct ntree *element_p()
{
  char *token = take_tok();
  
  if (!token || check_token_p(token) == 1)
    return redir_p();

  struct ntree *new = new_ntree(token, COMMAND);
  valid_tok();
  token = take_tok();
  
  while (token && check_token_p() == 0)
  {
    struct ntree *args = new_ntree(token, WORD);
    new = add_ntree(new, args);
    valid_tok();
    token = take_tok();
  }

  return new;
}
