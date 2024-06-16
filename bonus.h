#ifndef BONUS_H
#define BONUS_H

#define BOLD_ON "\e[1m"
#define OFF "\e[m"
#define UNDERLINE "\e[4m"
#define DOUBLE_SIZE sizeof(double)
#define PCHAR_SIZE sizeof(char*)

void manual(void); // a simple manual for the user
void group(char ch); // groups and prints the amount fo gender or enthnicity
void average(char ch); // calculates the average of the networths or the age
void median(char ch); // calculates the median of the networths or the age
int compare(const void *a, const void *b); // compares the values for the qsort function
int count_list(void); // counts the amount of nodes in the list

#endif