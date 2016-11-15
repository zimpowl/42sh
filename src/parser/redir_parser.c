#include "../include/tree.h"
#include "../include/parser.h"

struct ntree *redir_p()
{
  struct ntree *ntree = NULL;
  struct ntree *new = NULL;
  char *token = take_tok();
  char *token2 = take_next_tok();

  if (check_redir(token) == 1 || check_redir(token2) == 1)
  {
    if (check_redir(token2) == 1)
    {
      ntree = new_ntree(token2, REDIRECTION);
      if (check_ionumber(token) <= 0)
        return NULL;
      new = new_ntree(token, IO_NUMBER);
      ntree = add_ntree(ntree, new);
      valid_tok();
    }
    else
      ntree = new_ntree(token, REDIRECTION);
    valid_tok();
    token = take_tok();
    if (!token)
      return NULL;
    new = new_ntree(token, WORD);
    ntree = add_ntree(ntree, new);
  }
  return ntree;
}

int check_redir(char *tok)
{
  if (tok && (strcmp(tok, ">") == 0 || strcmp(tok, "<") == 0
      || strcmp(tok, ">>") == 0 || strcmp(tok, "<<") == 0
      || strcmp(tok, "<<-") == 0 || strcmp(tok, ">&") == 0
      || strcmp(tok, "<&") == 0 || strcmp(tok, ">|") == 0
      || strcmp(tok, "<>") == 0))
    return 1;
  return 0;
}

int check_ionumber(char *tok)
{
  int i = 0;
  if (!tok)
    return i;
  for (; tok[i]; i++)
  {
    if (tok[i] < 60 || tok[i] > 71)
      return 0;
  }
  return i;
}

