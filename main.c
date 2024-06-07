#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "lists.h"
#include "inputnfiles.h"
#include "main.h"
//#include "bonus.h"

billionare *head = NULL;

int main(void)
{
    int len1 = 0, len2 = 0, num = 0, i = 0, count = 0, count2 = 0, bonus = FALSE;
    char temp[MAX_SIZE] = {'\0'};
    char *token = NULL, *test_token = NULL;
    char *filename = NULL, ch = '\0', *str = NULL;

    srand(time(NULL));
    puts("Welcome to the Billionare list handler\n");
    
    while(TRUE)
    {
        putchar('&');
        putchar('>');
        putchar(' ');

        len1 = read_text(temp, MAX_SIZE, TRUE);

        if(!strncmp(temp, "exit", 4))
        {
            if(strlen(temp) != 4)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            free_list();

            break;
        }
        else if(!strncmp(temp, "newbil", 6))
        {
           if((token = strchr(temp, ' ')) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if(strlen(token) <= 1)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;  
            }

            write_node(token + 1);
        }
        else if(!strncmp(temp, "print", 5))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if(temp[5] != '+' && temp[5] != '-' && temp[5] != '=')
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            count = 0;
            count2 = 0;
            len2 = strlen(token);

            for(i = 0; i < len2; i++)
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

            if(i != len2)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if(count == 2)
            {
                print(temp[5], token, '/');
            }
            else if(count2 == 1)
            {
                print(temp[5], token, ':');
            }
            else if(count == 0 && count2 == 0 && atoi(token) >= 0)
            {
                print(temp[5], token, '\0');
            }
            else
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
        }
        else if(!strncmp(temp, "delete", 6))
        {
            if(temp[6] != 'N' && temp[6] != 'O' && strlen(temp) != 7)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            delete(temp[6]);
        }
        else if(!strncmp(temp, "find", 4))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if(temp[4] != 'N' && temp[4] != 'C' && temp[4] != 'S')
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            len2 = strlen(token);

            for(i = 0; i < len2; i++)
            {
                if(isdigit(token[i]) || !isprint(token[i]))
                {
                    puts("\nInvalid Input, please enter a valid one");
                    continue;
                }
            }

            if(token[0] == '*' && len2 == 1)
            {
                find('*', token);
            }
            else
            {
                find(temp[4], token);
            }
        }
        else if(!strncmp(temp, "load", 4))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if((num = atoi(token)) <= 0)
            {
                puts("Invalid Input, please enter a valid one");
                continue;
            }

            if((token = strtok(NULL, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            load(token, num);
        }
        else if(!strncmp(temp, "save", 4))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if((num = atoi(token)) <= 0)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            if((token = strtok(NULL, " ")) == NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            save(token, num);
        }
        else if(!strncmp(temp, "sum", 3))
        {
            if(strlen(temp) != 3)
            {
                puts("\nInvalid Input, please enter a valid one");
                continue;
            }

            printf("The sum of all networths is: %.2f\n", sum());
        }
        else if (!strncmp(temp, "bonus", 5))
        {
            bonus = TRUE;
        }
        // else if(!strncmp(temp, "man", 3) && bonus)
        // {
        //     manual();
        // }
        // else if(!strncmp(temp, "average", 7))
        // {
        //     if(temp[7] != 'N' && temp[7] != 'A')
        //     {
        //         puts("\nInvalid Input, please enter a valid one");
        //         continue;
        //     }

        //     average(temp[7]);
        // }
        else
        {
            puts("\nInvalid Input, please enter a valid one");
            continue;
        }
    }

    return EXIT_SUCCESS;
}