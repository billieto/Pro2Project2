#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "lists.h"
#include "inputnfiles.h"
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
    puts(BOLD_ON"  deleteN, deleteO, deleteA"OFF);
    puts("\tDeletes the newst (deleteN) or the oldest (deleteO) billionare from the list or all the billionares in the list.\n");
    puts(BOLD_ON"  exit"OFF);
    puts("\tExits the program.\n");
    puts(BOLD_ON"   averageA, averageN"OFF);
    puts("\tPrints the average Age or Networth of the billionares inserted in the list\n");
    puts(BOLD_ON"   medianA, medianN"OFF);
    puts("\tFinds the median Age or Networth of the billionares inserted in the list\n");
    puts(BOLD_ON"   groupG, groupE"OFF);
    puts("\tPrints the amount of Queer, Females and Males or the amount of ethnisities and their amount of billionares inserted in the list\n");
    puts(BOLD_ON"   count"OFF);
    puts("\tPrints the amount of billionares that are inserted in the list\n");
}

void group(char ch)
{
    int count = 0, count2 = 0, count3 = 0, *n = NULL, flag = FALSE, j = 0;
    char **groupn = NULL;
    billionare *temp = head;

    if(check_list_empty(head))
    {
        return;
    }

    switch(ch)
    {
        case 'G': // grouping the genders
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
            
            printf("\nThere are %d unknown/queer billionares\n", count3);
            printf("There are %d Female billionares\n", count2);
            printf("There are %d Male billionares\n", count);
         break;

        case 'E': // grouping ethnisisities
            while(TRUE)
            {
                if(groupn == NULL) // if we have no ethnisities allocated
                {
                    count++; // inc count because 1 ethnisity
                    groupn = (char**) malloc(PCHAR_SIZE * count);
                    check_malloc(groupn);

                    *groupn = (char*) malloc(CHAR_SIZE * temp -> id.ethnicitylen);
                    check_malloc(*groupn);
                    strcpy(*groupn, temp -> id.ethnisity);

                    n = (int*) malloc(INT_SIZE * count);
                    check_malloc(n);

                    n[0] = 1;
                }
                else // else we check the array if the ethnisity is already there if not we allocate memmory for it
                {
                    flag = FALSE;

                    for(j = 0; j < count; j++)
                    {
                        if(!strcmp(groupn[j], temp -> id.ethnisity))
                        {
                            n[j]++;
                            flag = TRUE;
                            break;
                        }
                    }

                    if(!flag)
                    {
                        count++;
                        groupn = (char**) realloc(groupn, PCHAR_SIZE * count);
                        check_malloc(groupn);

                        groupn[count - 1] = (char*) malloc(CHAR_SIZE * temp -> id.ethnicitylen);
                        check_malloc(groupn[count - 1]);
                        strcpy(groupn[count - 1], temp -> id.ethnisity);

                        n = (int*) realloc(n, INT_SIZE * count);
                        check_malloc(n);
                        n[count - 1] = 1;
                    }
                }

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }
            }

            for(j = 0; j < count; j++)
            {
                printf("In %s, %d billionares were born\n", groupn[j], n[j]);
            }

            for(j = 0; j < count; j++)
            {
                free(groupn[j]);
            }
            free(groupn);
            free(n);
         break;
    }
}

void average(char ch)
{
    double sums = 0, average = 0;
    int count = count_list();
    billionare *temp = head;

    if(check_list_empty(head))
    {
        return;
    }

    switch(ch)
    {
        case 'A': // average age
            while(TRUE)
            {
                sums += 2024 - temp -> birthdate.year; // Na to koita3w an mporw na to kanw me time.h

                temp = temp -> next;
                if(temp == head)
                {
                    break;
                }
            }

            average = sums / count;
            printf("\nThe average age of the billionares is %.2f\n", average);
         break;
        
        case 'N': // average networth
            sums = sum();

            average = sums / count;
            printf("\nThe average networth of the billionares is %.2f\n", average);
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

    if(check_list_empty(head))
    {
        return;
    }

    switch(ch)
    {
        case 'A': // median age
            array = (int*) malloc(INT_SIZE * len);
            check_malloc(array);

            while(TRUE)
            {
                array[i] = 2024 - temp -> birthdate.year; // Na to koita3w an mporw na to kanw me time.h

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

            printf("\nThe median age of the billionares is %.2f\n", median);

            free(array);
         break;

        case 'N': // median networth
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

            printf("\nThe median networth of the billionares is %.2f\n", median);

            free(array2);
         break;
    
    }
}

int count_list(void)
{
    int count = 0;
    billionare *temp = head;

    if(check_list_empty(head))
    {
        return 0;
    }

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