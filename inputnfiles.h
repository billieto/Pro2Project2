#ifndef INPUTNFILES_H
#define INPUTNFILES_H

#include <stdio.h>

void load(char *filename, int input); // gets n strings from a file and puts in the input
void save(char *filename, int input); // saves n strings to a file
void right_input(char *str); // makes the first letter of the string uppercase and all the other lower case
void check_malloc(void *ptr); // checks if the malloc function was successful
int check_input(char *str); // checks if the input of the user or the string from the file is in the right format
int check_file(FILE *file); // checks if the file was opened correctly
void read_text(char str[], int size, int flag); // reads the input from the user and removes the newline character
int leapyear(int year); // checks if the year is a leap year

#endif