#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "lists.h"
#include "bonus.h"

void manual(void) // inspired from grep manual
{
    puts(BOLD_ON"\nNAME"OFF);
    puts("\tBillionare list handler\n");
    puts(BOLD_ON"SYNOPSIS"OFF);
    printf(BOLD_ON"\t &> "OFF);
    putchar('[');
    printf(UNDERLINE"OPTION"OFF);
    printf("...] ");
    printf(UNDERLINE"NUMBER"OFF);
    putchar(' ');
    putchar('[');
    printf(UNDERLINE"FILE"OFF);
    printf("...]\n");
    printf(BOLD_ON"\t &> "OFF);
    putchar('[');
    printf(UNDERLINE"OPTION"OFF);
    printf("...] ");
    printf(UNDERLINE"NUMBER"OFF);
    putchar('\n');
    printf(BOLD_ON"\t &> "OFF);
    putchar('[');
    printf(UNDERLINE"OPTION"OFF);
    printf("...] ");
    printf(UNDERLINE"PATTERNS\n"OFF);
    printf(BOLD_ON"\t &> "OFF);
    putchar('[');
    printf(UNDERLINE"OPTION"OFF);
    printf("...]\n\n");
    puts(BOLD_ON"DESCRIPTION"OFF);
    puts("\tThis program is used to handle a list of billionares. The user can add, delete, print, save, load, sum and find billionares.");
    puts("\tThe user can also exit the program by typing 'exit'.\n");
    puts(BOLD_ON"OPTIONS"OFF);
    printf(BOLD_ON"  newbil "OFF);
    puts("<name>;<city/country>;<source>;<ethnisity>;<gender>;<birth date> <birthdate time>;<networth>");
    puts("\tAdd a new billionare to the list\n");
    printf(BOLD_ON"  print+, print-, print= "OFF);
    puts("<birth time> or <birth date> or <networth>");
    puts("\tPrints the billionares that the patterns are found in the list. '+' for greater, '-' for less and '=' for equal.\n");
    printf(BOLD_ON"  findN, findC, findS "OFF);
    puts("<name> or <city> or <source> or *");
    puts("\tFinds the billionares that the patterns are found in the list. With '*' it prints all the billionares that are loaded.\n");
    printf(BOLD_ON"  load "OFF);
    puts("<number> <file>");
    puts("\tLoads the number of billionares from the file. If the number is greater than the number of billionares in the file, it loads all the billionares.\n");
    printf(BOLD_ON"  save "OFF);
    puts("<number> <file>");
    puts("\tSaves the number of billionares to the file. If the number is greater than the number of billionares in the list, it saves all the billionares.");
    puts("\tIt also creates the file if it does not exist.\n");
    puts(BOLD_ON"  sum"OFF);
    puts("\tPrints the sum of the networth of the billionares in the list.\n");
    puts(BOLD_ON"  deleteN, deleteO"OFF);
    puts("\tDeletes the newst (deleteN) or the oldest (deleteO) billionare from the list.\n");
    puts(BOLD_ON"  exit"OFF);
    puts("\tExits the program.");
    puts(BOLD_ON"   averageA, averageN"OFF);
    puts("\tFinds the average Age on Net worth of the billionares inserted in the list\n");
    puts(BOLD_ON""OFF);
}// NA BALW KAI TA KAINOURIA :D

void group(char ch)
{
    int count = 0, count2 = 0, count3 = 0, *n = NULL, i = 0, j = 0;
    char **groupn = NULL;
    billionare *temp = head, *temp2 = head;

    if(check_list_empty(head))
    {
        return;
    }

    switch(ch)
    {
        case 'G':
            while(TRUE)
            {
                if(temp -> id.gender == 'M')
                {
                    count++;
                }
                else if(temp -> id.gender == 'F')
                {
                    count2++;
                }
                else
                {
                    count3++;
                }

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }
            }
            
            printf("There are %d unknown/queer billionares\n", count3);
            printf("There are %d Female billionares\n", count2);
            printf("There are %d Male billionares\n", count);
         break;

        case 'E':
            while(TRUE)
            {
                if(groupn == NULL)
                {
                    groupn = (char**) malloc(sizeof(char*) * (count + 1));
                    check_malloc(groupn);

                    *groupn = (char*) malloc(CHAR_SIZE * temp -> id.ethnicitylen);
                    check_malloc(*groupn);
                    strcpy(*groupn, temp -> id.ethnisity);

                    n = (int*) malloc(INT_SIZE);
                    check_malloc(n);

                    *n++;

                    i++;
                }
                else
                {
                    for(j = 0; j < i; i++)
                    {
                        if(!strcmp(groupn[j], temp -> id.ethnisity))
                        {
                            n[j]++;
                            break;
                        }
                        else
                        {
                            groupn = (char**) realloc(groupn, PCHAR_SIZE * (count + 1));
                            check_malloc(groupn);

                            groupn[j] = (char*) malloc(CHAR_SIZE * temp -> id.ethnicitylen);
                            check_malloc(groupn[j]);
                            strcpy(groupn[j], temp -> id.ethnisity);

                            n = (int*) realloc(n, INT_SIZE * (count + 1));
                            check_malloc(n);

                            n[j] = 1;

                            i++;
                        }
                    }
                }

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }
            }

            for(j = 0; j < i; j++)
            {
                printf("In %s, %d billionares were born\n", groupn[j], n[j]);
            }
         break;
    }

    for(j = 0; j < i; j++)
    {
        free(groupn[j]);
    }
    free(groupn);
    free(n);
}

void average(char ch)
{
    double sums = 0, average = 0;
    int count = count_list();
    billionare *temp = head;

    switch(ch)
    {
        case 'A':
            while(TRUE)
            {
                sums += 2024 - atoi(temp -> birthdate.year); // Na to koita3w an mporw na to kanw me time.h

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }
            }

            average = sums / count;
            printf("The average age of the billionares is %.2f\n", average);
         break;
        
        case 'N':
            sums = sum();

            average = sums / count;
            printf("The average networth of the billionares is %.2f\n", average);
         break;
    }
}

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void median(char ch)
{
    int len = count_list(), i = 0, *array = NULL;
    double median = 0, *array2 = NULL;
    billionare *temp = head;

    switch(ch)
    {
        case 'A':
            array = (int*) malloc(INT_SIZE * len);
            check_malloc(array);

            while(TRUE)
            {
                array[i] = 2024 - atoi(temp -> birthdate.year); // Na to koita3w an mporw na to kanw me time.h

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }

                i++;
            }

            qsort(array, len, INT_SIZE, compare);

            if(len % 2 == 0)
            {
                median = (array[len / 2] + array[(len / 2) - 1]) / 2;
            }
            else
            {
                median = array[len / 2];
            }

            printf("The median age of the billionares is %.2f\n", median);

            free(array);
         break;

        case 'N':
            array2 = (double*) malloc(DOUBLE_SIZE * len);
            check_malloc(array2);

            while(TRUE)
            {
                array2[i] = temp -> id.networth;

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }

                i++;
            }

            qsort(array2, len, DOUBLE_SIZE, compare);

            if(len % 2 == 0)
            {
                median = (array2[len / 2] + array2[(len / 2) - 1]) / 2;
            }
            else
            {
                median = array2[len / 2];
            }

            printf("The median networth of the billionares is %.2f\n", median);

            free(array2);
         break;
    
    }
}

int count_list(void)
{
    int count = 0;
    billionare *temp = head;

    while(TRUE)
    {
        count++;

        temp = temp -> next;
        if(temp == head)
        {
            break;
        }
    }

    return count;
}