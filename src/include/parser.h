#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//main
void init_tok(char *argv[], int len);
char* take_tok();
char* take_next_tok();
void valid_tok();


//input_parser.c
struct ntree *input_parser();
//list_parser.c
struct ntree *list_p();
struct ntree *compound_list_p();
struct ntree *do_group_p();
//and_or_parser.c
struct ntree *and_or_p();
//pipeline_parser.c
struct ntree *pipeline_p();
//command_parser.c
struct ntree *command_p();
struct ntree *simple_command_p();
struct ntree *prefix_p();
struct ntree *element_p();
//shellcom_parser.c
struct ntree *shell_command_p();
struct ntree *shell_commandbis_p();
//rules_parser.c
struct ntree *rule_if_p();
//func_parser.C
struct ntree *func_p();
//redir_parser.c
struct ntree *redir_p();
int check_redir(char *tok);
int check_ionumber(char *tok);

//useful everywhere in input_parser.c
int skip_line();
int check_token_p();

//read_parser
int read_p(struct ntree *ntree);

#endif
