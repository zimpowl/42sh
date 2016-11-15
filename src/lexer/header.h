#ifndef _HEADER_LEXER_H
#define _HEADER_LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

extern struct list_token *g_list;

enum type_token
{
  OPERATOR,
  WORD,
  WORD_DQUOTED,
  WORD_QUOTED
};

struct token
{
  enum type_token type;
  char *s;
};

struct list_token
{
  struct token token;
  struct list_token *next;
  size_t i;   //index token
};

char *append(char *s, char c);          //MALLOC  append =


void my_delete(char *s, size_t i); //REALLOC s

void delete_space(char *s);


//type.c
int is_quoted(const char c);
int is_dquoted(const char c);

//static int is_operator1(const char *s);
//static int is_operator2(const char *s);
//static int is_operator3(const char *s);
int is_operator(char *tmp);

enum type_token take_type(char *s, char c, enum type_token type);


struct token init_token(size_t i);

int is_continue(struct token tok, size_t i);


struct token new_token(struct token prev, size_t i);


struct list_token *init_list_token(size_t i);


struct list_token *take_1_token(size_t i);

//lexer.c
//char *take_token();
//void valid_tok();
//void init_lexer(char *s); //MALLOC g_line

#endif
