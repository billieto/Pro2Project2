#ifndef LISTS_H
#define LISTS_H

#include "main.h"

void write_node(char *str);
void free_list(void);
void find(char ch, char *str);
void print(char ch, char *str);
void delete(char ch);
void inisialize(char **str, int *len, char *token);
void u_inisialize(char **str, int *len, char *token);
void sum(void);
void simple_print(billionare *temp);
int check_list_empty(billionare *head);

#endif