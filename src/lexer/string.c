#include "header.h"

char *append(char *s, char c)          //MALLOC  append =
{
  size_t len = strlen(s);
  char *res = malloc((len + 1) * sizeof (char));
  res[0] = '\0';
  res = strcpy(res, s);
  res[len] = c;
  return res;
}

void my_delete(char *s, size_t i) //REALLOC s
{
  size_t len = strlen(s);
  memmove(&s[i], &s[i + 1], len - i);
  s = realloc(s, (len - 1) * sizeof (char));
  s[len] = '\0';
}
void delete_space(char *s)
{
  int b = 1;
  size_t len = strlen(s);
  int i = 0;
  for (int l = 0; l < len; l++)
  {
    if ((s[i] == ' ' || s[i] == '\t') && b)
    {
      my_delete(s, i);
    }
    else
    {
      if (s[i] == ' ' || s[i] == '\t')
        b = 1;
      else
        b = 0;
      i++;
    }
  }
}
