#include "header.h"

int is_quoted(const char c)
{
  return c == '\'';
}

int is_dquoted(const char c)
{
  return c == '"';
}

static int is_operator1(const char *s)
{
  return s[0] == '&' || s[0] == ';' || s[0] == '<' || s[0] == '>';
}

static int is_operator2(const char *s)
{
  return !(strcmp(s, "&&") && strcmp(s, ";;") && strcmp(s, "<<") && 
           strcmp(s, ">>") && strcmp(s, "<&") && strcmp(s, ">&") && 
           strcmp(s, "<>") && strcmp(s, ">|"));
}

static int is_operator3(const char *s)
{
  return !(strcmp(s, "<<-"));
}

int is_operator(char *tmp)
{

  size_t len = strlen(tmp);
  int res = 0;
  if (len == 1)
    res = is_operator1(tmp);
  else if (len == 2)
    res = is_operator2(tmp);
  else if (len == 3)
    res = is_operator3(tmp);
  return res;
}

enum type_token take_type(char *s, char c, enum type_token type)
{
  char *tmp = append(s, c);
  size_t len = strlen(tmp);
 int res = 0;
  res = is_operator(tmp);
 
 free(tmp);
  if (res)
    return OPERATOR;
  else
  {
   // if (type == WORD_QUOTED)
      res = is_quoted(s[len - 2]);
  //  else
   //   res = is_quoted(c);
    if ((res && type != WORD_QUOTED) || (type == WORD_QUOTED && !res))
      return WORD_QUOTED;
    else if (res && type == WORD_QUOTED)
      return WORD;
  }
 return WORD;
}
