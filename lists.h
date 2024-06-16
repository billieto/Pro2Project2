#ifndef LISTS_H
#define LISTS_H

#include "main.h"

#define INT_SIZE sizeof(int)

void write_node(char *str); // allocates memory for the new node and writes the data to the node
void free_list(void); // frees the list
void find(char ch, char *str); // finds a pattern given by the user and prints the node with the pattern (its works with letters: names, cities, countries, sources)
void print(char ch, char *str, char print); // given a pattern it prints the nodes with the pattern (it works with numbers: hours and minutes, days, months and years, and networths)
void delete(char ch); // deletes the newest or the oldest node
double sum(void); // sums the networths of the nodes
void all_lower(char *str, int len); // makes all the letters in the string lowercase
void simple_print(billionare *temp, int *flag); // prints the data of the node
void bank_account(billionare *new); // generates a random bank account for the node
int check_list_empty(billionare *head); // checks if the list is empty

#endif