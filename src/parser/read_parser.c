#include "../include/tree.h"
#include "../include/parser.h"
#include "../include/executor.h"

int command(struct ntree *ntree)
{
   char *co[ntree->size + 1];
   co[0] = ntree->name;
   for (unsigned i = 0; i < ntree->size; i++)
   {
    co[i+1] = ntree->sons[i]->name;
   }
   co[ntree->size + 1] = NULL;
  return exec(co);
}

int and_or_l(struct ntree *ntree)
{
  if (strcmp(ntree->name, "&&") == 0)
  {
    int res = command(ntree->sons[0]);
    if (res == 0)
      return command(ntree->sons[1]);
    else
      return res;
  }
  return 0;
}

int read_p(struct ntree *ntree)
{
  if (ntree && ntree->token == AND_OR)
    return and_or_l(ntree);
  return 0;
}


