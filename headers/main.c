#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lists.h"
#include "inputnfiles.h"
#include "main.h"

billionare *head = NULL;

int main(void)
{
    int len1 = 0, len2 = 0, num = 0, i = 0, count = 0, count2 = 0;
    char temp[MAX_SIZE] = {'\0'};
    char *token = NULL, *test_token = NULL;
    char *filename = NULL, ch = '\0', *str = NULL;
    

    while(TRUE)
    {
        putchar('&');
        putchar('>');

        len1 = read_text(temp, MAX_SIZE, TRUE);

        if(!strncmp(temp, "exit", 4))
        {
            free_list();
            break;
        }
        else if(!strncmp(temp, "newbil", 6))
        {
           if((token = strchr(temp, ' ')) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            write_node(token + 1);
        }
        else if(!strncmp(temp, "print", 5))
        {
            if((token = strtok(temp, " ")) == NULL) // Mporw auta na ta blaw se sunartisi
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("Invalid Input, please enther a valid one");            
                continue;
            }

            if(temp[5] != '+' && temp[5] != '-' && temp[5] != '=')
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            for(i = 0; i < strlen(token); i++)
            {
                if(!isdigit(token[i]) && token[i] != '/' && token[i] != ':')
                {
                    puts("Invalid Input, please enther a valid one");
                    continue;
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

            if((count != 3 && count2 != 0)|| (count2 != 1 && count != 0))
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            print(temp[5], token);
        }
        else if(!strncmp(temp, "delete", 6))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) != NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if(temp[6] != 'N' && temp[6] != 'O')
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            delete(temp[6]);

            continue;
        }
        else if(!strncmp(temp, "find", 4))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("Invalid Input, please enther a valid one");            
                continue;
            }

            if(temp[4] != 'N' && temp[4] != 'C' && temp[4] != 'S')
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if(token[0] == '*' && strlen(token) == 1)
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
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if((num = atoi(token)) == 0)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if((token = strtok(NULL, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            load(token, num);
        }
        else if(!strncmp(temp, "save", 4))
        {
            if((token = strtok(temp, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((token = strtok(NULL, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if((num = atoi(token)) == 0)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            if((token = strtok(NULL, " ")) == NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }
            else if((test_token = strtok(NULL, " ")) != NULL)
            {
                puts("Invalid Input, please enther a valid one");
                continue;
            }

            save(token, num);
        }
        else if(!strncmp(temp, "sum", 3))
        {
            sum();
        }
        else
        {
            puts("Invalid command, please enther a valid one");
            continue;
        }
    }

    return EXIT_SUCCESS;
}