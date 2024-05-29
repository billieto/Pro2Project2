#ifndef INPUTNFILES_H
#define INPUTNFILES_H

#include <stdio.h>

void load(char *filename, int input);
void save(char *filename, int input);
void check_malloc(void *ptr);
int check_input(char *str);
int check_file(FILE *file);
int read_text(char str[], int size, int flag);
int isalphabetic(char ch);
void right_input(char *str);

#endif