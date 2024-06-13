#ifndef BONUS_H
#define BONUS_H

#define BOLD_ON "\e[1m"
#define OFF "\e[m"
#define UNDERLINE "\e[4m"
#define DOUBLE_SIZE sizeof(double)
#define PCHAR_SIZE sizeof(char*)

void manual(void);
void group(char ch); 
void average(char ch);
void median(char ch);
int compare(const void *a, const void *b);
int count_list(void);

#endif