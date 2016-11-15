#include "header.h"

char *g_line = '\0';
struct list_token *g_list = NULL;

struct token init_token(size_t i)
{
  struct token tok;
  tok.type = take_type("", g_line[i], WORD);
  tok.s = malloc(sizeof (char));        // MALLOC INIT
  tok.s[0] = g_line[i];
  // g_i++;
  return tok;
}


int is_continue(struct token tok, size_t i)
{
  if (tok.type == WORD_QUOTED)
    return take_type(tok.s, g_line[i], tok.type) == WORD_QUOTED;
  if (g_line[i] == ' ' || g_line[i] == '\n' || g_line[i] == '\0')
  {
    //  g_i++;
    return 0;
  }
  if (tok.type == OPERATOR)
    return take_type(tok.s, g_line[i], tok.type) == OPERATOR;
  else
    return take_type("", g_line[i], tok.type) == WORD;
}

struct token new_token(struct token prev, size_t i)
{
  struct token res;
  res.type = take_type(prev.s, g_line[i], prev.type);
  res.s = append(prev.s, g_line[i]);             //MALLOC
  // i++
  return res;
}

struct list_token *init_list_token(size_t i)
{
  struct list_token *list = malloc(sizeof (struct list_token));
  list->next = NULL;
  list->token = init_token(i);
  list->i = i + 1;
  return list;
}

struct list_token *take_1_token(size_t i)
{
  if (/*g_line[g_i] == '\n' || */g_line[i] == '\0')
  {
    free(g_line);
    return NULL;
  }
  struct list_token *my_list = init_list_token(i);
  i++;
  int cont = 0;
  do
  {
    cont = is_continue(my_list->token, i);
    if ((g_line[i] == ' ' || g_line[i] == '\0') && my_list->token.type != WORD_QUOTED)
      i++;
    if (cont)
    {
      my_list->token = new_token(my_list->token, i);
      i++;
    }
  } while (cont);

  my_list->i = i;
  return my_list;
}

char *take_token()
{
  if (g_list)
    return g_list->token.s;
  free(g_line);
  return NULL;
}

void valid_tok()
{
  if (!g_list)
    return;
  struct list_token *tmp = g_list;
  g_list = g_list->next;
  free(tmp->token.s);
  free(tmp);
  if (!g_list)
    return;
  g_list->next = take_1_token(g_list->i);
}

void init_lexer(char *s)  //MALLOC g_line
{
  size_t len = strlen(s);
  g_line = malloc(len * sizeof (char));
  g_line = strcpy(g_line, s);
  g_line[len] = '\0';
  delete_space(g_line);
  g_list = take_1_token(0);
  g_list->next = take_1_token(g_list->i);
}

/*int main(int argc, char *argv[])
{
  if (argc != 2)
    errx(1, "Number of argument = 1");
  init_lexer(argv[1]);
  char *s = take_token();
  while (s)
  {
    printf("%s\n", s);
    //  free(s);
    // s = NULL;
    valid_tok();
    s = take_token();
  }
  printf("first token = %s\n", s);
  printf("g_line = %s\n", g_line);

  free(s);
  return 0;
}*/
