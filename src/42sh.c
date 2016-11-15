#include <stdio.h>
#include "include/42sh.h"

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    if (!strcmp(argv[1], "-c"))
    {
      init_lexer(argv[2]);
      char *s = take_token();
      while (s)
      {
      printf("%s\n", s);
      valid_tok();
      s = take_token();
//      free(s);
     }
     // init_parser(argv[2]);
    }
  }
  return 0;
}
