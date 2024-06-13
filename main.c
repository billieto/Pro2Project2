// Name: Vasileios Sakellariou Kyrou
// email: dit23037@go.uop.gr
// AM: 2022202300037
// 
// Name: Nikolaos Milonas
// email: dit23128@go.uop.gr
// AM: 2022202300128
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "lists.h"
#include "inputnfiles.h"
#include "main.h"

#if BONUS // if you want to enable the bonus elements you have to define BONUS to TRUE in the main.h file 
#include "bonus.h"
#endif    

billionare *head = NULL;

int main(void)
{
    int len2 = 0, num = 0, i = 0, count = 0, count2 = 0;
    char temp[MAX_SIZE] = {'\0'}; // acts as a buffer for the input
    char *token = NULL, *test_token = NULL; // acts as checking methods for the input

    srand(time(NULL));

    puts("Welcome to the Billionare list handler");
    
    while(TRUE)
    {
        putchar('\n');
        putchar('&');
        putchar('>');
        putchar(' ');

        read_text(temp, MAX_SIZE, TRUE);

        if(!strcmp(temp, "exit"))
        {
            free_list();
            break;
        }
        else if(!strncmp(temp, "newbil", 6))
        {
            if((token = strchr(temp, ' ')) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid command, please enter a valid one");
                continue;
            }
            else if(strlen(token) <= 1) // because i use strchr and not strtok as of below i check the len on the token so i can avoid segmentation fault
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            write_node(token + 1);
        }
        else if(!strncmp(temp, "print", 5))
        {
            if((token = strtok(temp, " ")) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL) // if there is no other token then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL) // if there are more than 2 tokens then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            if(temp[5] != '+' && temp[5] != '-' && temp[5] != '=') // if the command is not print+ or print- or print= then it is invalid
            {
                puts("\nInvalid command, please enter a valid one");
                continue;
            }

            count = 0;
            count2 = 0;
            len2 = strlen(token);

            for(i = 0; i < len2; i++) // i check if the input is valid
            {
                if(!isdigit(token[i]) && token[i] != '/' && token[i] != ':')
                {
                    break;
                }
                else if(token[i] == '/')
                {
                    count++;
                }
                else if(token[i] == ':')
                {
                    count2++;
                }
            }

            if(i != len2) // if the input is not valid then i print an error message
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            if(count == 2) // xx/xx/xxx correct! 2 '/'
            {
                print(temp[5], token, '/');
            }
            else if(count2 == 1) // xx:xx correct! 1 ':'
            {
                print(temp[5], token, ':');
            }
            else if(count == 0 && count2 == 0 && atoi(token) >= 0) // if there are no '/' or ':' then it is a number!
            {
                print(temp[5], token, '.');
            }
            else // else it is invalid
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
        }
        else if(!strcmp(temp, "deleteN") || !strcmp(temp, "deleteO"))
        {
            delete(temp[6]);
        }
        else if(!strncmp(temp, "find", 4))
        {
            if(temp[4] != 'N' && temp[4] != 'C' && temp[4] != 'S') // if the command is not findN or findC or findS then it is invalid
            {
                puts("\nInvalid command, please enter a valid one");
                continue;
            }
            else if((token = strtok(temp, " ")) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL) // if there is no other token then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL) // if there are more than 2 tokens then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            len2 = strlen(token);

            for(i = 0; i < len2; i++) // i check if the input is valid
            {
                if(isdigit(token[i]) || !isprint(token[i]))
                {
                    break;
                }
            }

            if(i != len2) // if the input is not valid then i print an error message
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            if(token[0] == '*' && len2 == 1) // if the input is '*' then i print all the billionares
            {
                find('*', token);
            }
            else if(token[0] != '*') // else i print the billionare with the parameter that the user gave
            {
                find(temp[4], token);
            }
            else // else it is invalid
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
        }
        else if(!strncmp(temp, "load", 4))
        {
            if((token = strtok(temp, " ")) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL) // if there is no other token then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((num = atoi(token)) <= 0) // if the number is less than 0 then it is invalid
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL) // if there are more than 2 tokens then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            load(token, num);
        }
        else if(!strncmp(temp, "save", 4))
        {
            if((token = strtok(temp, " ")) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL) // if there is no other token then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((num = atoi(token)) <= 0) // if the number is less than 0 then it is invalid
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL) // if there are no spaces it means wrong input
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL) // if there are more than 2 tokens then the input is wrong
            {
                puts("\nInvalid argument, please enter a valid one");
                continue;
            }

            save(token, num);
        }
        else if(!strcmp(temp, "sum"))
        {
            if((num = sum()))
            {
                printf("\nThe sum of all networths is: %.2f\n", sum());
            }
        }
        #if BONUS // this is the bonus part of the code, to turn them on you need to define BONUS to TRUE in the main.h file
        else if(!strcmp(temp, "man"))
        {
            manual();
        }
        else if(!strcmp(temp, "averageN") || !strcmp(temp, "averageA"))
        {
            average(temp[7]);
        }
        else if(!strcmp(temp, "groupG") || !strcmp(temp, "groupE"))
        {
            group(temp[5]);
        }
        else if(!strcmp(temp, "medianA") || !strcmp(temp, "medianN"))
        {
            median(temp[6]);
        }
        else if(!strcmp(temp, "count"))
        {
            if((num = count_list()))
            {
                printf("\nThere are %d entries in the list\n", num);
            }
        }
        else if(!strcmp(temp, "deleteA"))
        {
            free_list();
        }
        #endif
        else
        {
            puts("\nInvalid command, please enter a valid one\nYou can use the command \"man\" to seek help");
        }
    }

    return EXIT_SUCCESS;
}