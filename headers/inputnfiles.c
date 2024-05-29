#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "lists.h"
#include "inputnfiles.h"

void save(char *filename, int input)
{
    FILE *save = NULL;
    billionare *temp = head;
    int i = 0;

    save = fopen(filename, "w");
    if(check_file(save))
    {
        return;
    }

    while(i < input)
    {
        fprintf(save, "%s;", temp -> id.name);
        fprintf(save, "%s/%s;", temp -> corp.city, temp -> corp.country);
        fprintf(save, "%s;", temp -> corp.source);
        fprintf(save, "%s;", temp -> id.ethnisity);
        fprintf(save, "%c;", temp -> id.gender);
        if(temp -> birthtime.hour < 10 && temp -> birthtime.minutes < 10)
        {
            fprintf(save, "%d/%d/%d 0%d:0%d;", temp -> birthdate.day, temp -> birthdate.month, temp -> birthdate.year, temp -> birthtime.hour, temp -> birthtime.minutes);
        }
        else if(temp -> birthtime.hour < 10)
        {
            fprintf(save, "%d/%d/%d 0%d:%d;", temp -> birthdate.day, temp -> birthdate.month, temp -> birthdate.year, temp -> birthtime.hour, temp -> birthtime.minutes);
        }
        else if(temp -> birthtime.minutes < 10)
        {
            fprintf(save, "%d/%d/%d %d:0%d;", temp -> birthdate.day, temp -> birthdate.month, temp -> birthdate.year, temp -> birthtime.hour, temp -> birthtime.minutes);
        }
        else
        {
            fprintf(save, "%d/%d/%d %d:%d;", temp -> birthdate.day, temp -> birthdate.month, temp -> birthdate.year, temp -> birthtime.hour, temp -> birthtime.minutes);
        }
        fprintf(save, "%.1f\n", temp -> id.networth);

        i++;

        temp = temp -> next;

        if(temp == head)
        {
            break;
        }
    }

    fclose(save);
}

void load(char *filename, int input)
{
    FILE *file = NULL;
    int len = 0, i = 0;
    char temp[MAX_SIZE] = {'\0'}, *str = NULL, *str2 = NULL;

    file = fopen(filename, "r");
    if(check_file(file))
    {
        return;
    }

    while((fgets(temp, MAX_SIZE, file) != NULL) && i < input)
    {
        len = strlen(temp);
        str = (char*) malloc((len + 1) * CHAR_SIZE);
        check_malloc(str);
        strcpy(str, temp);

        len = strlen(str);
        str2 = (char*) malloc((len + 1) * CHAR_SIZE);
        check_malloc(str2);
        strcpy(str2, str);

        if(check_input(str2))
        {
            break;
        }
        
        write_node(str);

        free(str);

        i++;
    }

    fclose(file);
}

void right_input(char *str)
{
    int i = 0;

    for(i = 0; i < strlen(str); i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }

    str[0] = toupper(str[0]);
}

int check_input(char *str)
{
    int len = 0, i = 0, j = 0, count = 0, count2 = 0, count3 = 0;
    char *token = NULL, *chr = NULL;
    float num = 0;

    while((token = strtok(str, ";")) != NULL)
    {
        
        switch(j)
        {
            case 0:
                len = strlen(token);

                if(len == 0)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                for(i = 0; i < len; i++)
                {
                    if(isdigit(token[i]))
                    {
                        puts("Invalid Input, please enther a valid one");
                        return TRUE;
                    }
                    else if(token[i] == ' ') // Den xreiazete
                    {
                        count++;
                    }
                    else if(token[i] == '&')
                    {
                        count2++;
                    }
                    else if(token[i] == ',')
                    {
                        count3++;
                    }
                }

                // if(count < 1 || count2 > 1 || count3 > 1)
                // {
                //     puts("Invalid Input, please enther a valid one");
                //     return TRUE;
                // }

                str = NULL;
             break;

            case 1:
                count = 0;

                len = strlen(token);

                if(len == 0)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                for(i = 0; i < len; i++)
                {
                    if(isdigit(token[i]) && token[i] != ' ' && token[i] != '/' && token[i] != '(' && token[i] != ')')
                    {
                        puts("Invalid Input, please enther a valid one");
                        return TRUE;
                    }
                    else if(token[i] == '/')
                    {
                        count++;
                    }
                }

                if(count != 1)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }
             break;

            case 2:
                count = 0;
                count2 = 0;

                len = strlen(token);

                if(len == 0)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                for(i = 0; i < len; i++)
                {
                    if(!isprint(token[i]))
                    {
                        puts("Invalid Input, please enther a valid one");
                        return TRUE;
                    }
                }

             break;

            case 3:
                len = strlen(token);

                if(len == 0)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }
                else if(len == 1 && token[0] == '?')
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                for(i = 0; i < len; i++)
                {
                    if(!isalpha(token[i]) && token[i] != ' ' && token[i] != '?' && token[i] != '(' && token[i] != ')' && token[i] != '.')
                    {
                        puts("Invalid Input, please enther a valid one");
                        return TRUE;
                    }
                }
             break;

            case 4:
                len = strlen(token);

                if(len != 1 && token[0] != 'M' && token[0] != 'F' && token[0] != '?')
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }
             break;

            case 5:
                count = 0;
                count2 = 0;
                count3 = 0;

                len = strlen(token);

                if(len == 0)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                for(i = 0; i < len; i++)
                {
                    if(isalpha(token[i]) && token[i] != '/' && token[i] != ' ' && token[i] != ':')
                    {
                        puts("Invalid Input, please enther a valid one");
                        return TRUE;
                    }
                    else if(token[i]  == '/')
                    {
                        count++;
                    }
                    else if(token[i] == ' ')
                    {
                        count2++;
                    }
                    else if(token[i] == ':')
                    {
                        count3++;
                    }
                }

                if(count != 2 || count2 != 1 || count3 != 1)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                chr = strchr(token, '/');
                if(atoi(token) < 1 || atoi(token) > 31 || atoi(chr + 1) < 1 || atoi(chr + 1) > 12) // m-porw na kanw elenxw gia to an einai febrouarios kai exei 30 h 31
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                chr[0] = '.';
                chr = strchr(token, '/');

                if(atoi(chr + 1) < 1900 || atoi(chr + 1) > 2024)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                chr = strchr(token, ' ');
                if(atoi(chr + 1) < 0 || atoi(chr + 1) > 23)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }

                chr = strchr(token, ':');
                if(atoi(chr + 1) < 0 || atoi(chr + 1) > 59)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }
             break;

            case 6:
                num = atof(token);

                if(num < 0)
                {
                    puts("Invalid Input, please enther a valid one");
                    return TRUE;
                }
             break;
        }

        j++;
    }

    if(j != 7)
    {
        puts("Invalid Input, please enther a valid one");
        return TRUE;
    }

    return FALSE;
}

// int isalphabetic(char ch)
// {
//     if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= 199 && ch <= 255))
//     {
//         return TRUE;
//     }

//     return FALSE;
// }

int check_list_empty(billionare *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return TRUE;
    }

    return FALSE;
}

void check_malloc(void *ptr)
{
    if(ptr == NULL)
    {
        printf("Error: allocating memory failed\n");
        exit(EXIT_FAILURE);
    }
}

int check_file(FILE *file)
{
    if(file == NULL)
    {
        printf("Error: cant open file or file name is incorect\n");
        return TRUE;
    }

    return FALSE;
}

int read_text(char str[], int size, int flag)
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    len = strlen(str);
    if(len > 0)
    {
        if(flag && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
            len--;
        }
        else
        {
            printf("Error: too few characters\n");
            exit(EXIT_FAILURE);
        }
        
        return len;
    }

    return EOF;
}