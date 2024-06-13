#ifndef LISTS_H
#define LISTS_H

#include "main.h"

#define INT_SIZE sizeof(int)

void write_node(char *str);
void free_list(void);
void find(char ch, char *str);
void print(char ch, char *str, char print);
void delete(char ch);
void inisialize(char **str, int *len, char *token);
double sum(void);
void all_lower(char *str, int len);
void simple_print(billionare *temp, int *flag);
void bank_account(billionare *new);
int check_list_empty(billionare *head);

#endif