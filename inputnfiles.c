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
    int i = 0, j = 0;

    if(check_list_empty(head))
    {
        return;
    }

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
        fprintf(save, "%.1f;", temp -> id.networth);
        for(j = 0; j < 10; j++)
        {
            fprintf(save, "%d", temp -> id.bank[j]);
        }
        fprintf(save, "\n");

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
    int i = 0;
    char temp[MAX_SIZE] = {'\0'}, *str = NULL, *str2 = NULL;

    file = fopen(filename, "r");
    if(check_file(file))
    {
        return;
    }

    while((fgets(temp, MAX_SIZE, file) != NULL) && i < input)
    {
        str = strdup(temp);
        check_malloc(str);

        str2 = strdup(str);
        check_malloc(str2);

        if(check_input(str2))
        {
            free(str);
            free(str2);
            break;
        }

        free(str2);

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
            case 0: // checking name
                len = strlen(token);
                count = 0;
                count2 = 0;

                if(!len) // checking if name is empty
                {
                    puts("\nWrong input in list, name cant be empty");
                    return TRUE;
                }

                for(i = 0; i < len; i++) // checking if name contains invalid characters
                {
                    if(isdigit(token[i]) && !isprint(token[i]) && token[i] != ' ' && token[i] != '&' && token[i] != '.' && token[i] != '-')
                    {
                        puts("\nWrong input in list, name cant containe numbers or invalid characters");
                        return TRUE;
                    }
                    else if(isalpha(token[i]))
                    {
                        count++;
                    }
                    else
                    {
                        count2++;
                    }
                }

                if(count < count2) // checking if name contains less letters than other characters
                {
                    puts("\nWrong input in list, name cannot containe less letters than other characters");
                    return TRUE;
                }

                str = NULL;
             break;

            case 1: // checking city and country
                len = strlen(token);
                count = 0;
                count2 = 0;
                count3 = 0;

                if((chr = strchr(token, '/')) == NULL) // checking if city and country are seperated by '/'
                {
                    puts("\nWrong input in list, city or country of source must have a '/'");
                    return TRUE;
                }
                
                chr[0] = '\0';

                if(!strlen(token)) // checking if city is empty
                {
                    puts("\nWrong input in list, city of source cant be empty");
                    return TRUE;
                }
                else if(!strlen(chr + 1)) // checking if country is empty
                {
                    puts("\nWrong input in list, country of source cant be empty");
                    return TRUE;
                }
                
                for(i = 0; i < len; i++) // checking if city and country contain invalid characters
                {
                    if(isdigit(token[i]) && !isprint(token[i]) && token[i] != ' ' && token[i] != '\0' && token[i] != '(' && token[i] != ')' && token[i] != '?')
                    {
                        puts("\nWrong input in list, city of source cant containe numbers or any other special characters");
                        return TRUE;
                    }
                    else if(isalpha(token[i]))
                    {
                        count2++;
                    }
                    else
                    {
                        count3++;
                    }
                }

                if(count2 < count3 && token[0] != '?' && chr[1] != '?' && strlen(token) != 1 && strlen(chr) != 1) // checking if city contains less letters than other characters
                {
                    puts("\nWrong input in list, city or country of source cant containe less letters than other characters");
                    return TRUE;
                }
             break;

            case 2: // checking source
                len = strlen(token);
                count = 0;
                count2 = 0;

                if(!len) // checking if source is empty
                {
                    puts("\nWrong input in list, source can not be empty");
                    return TRUE;
                }

                for(i = 0; i < len; i++) // checking if source contains invalid characters
                {
                    if(!isprint(token[i]))
                    {
                        puts("\nWrong input in list, source can not containe invalid characters");
                        return TRUE;
                    }
                    else if(isalpha(token[i]))
                    {
                        count++;
                    }
                    else
                    {
                        count2++;
                    }
                }

                if(count < count2) // checking if source contains less letters than other characters
                {
                    puts("\nWrong input in list, source cant containe less letters than other characters");
                    return TRUE;
                }
             break;

            case 3: // checking ethnisity
                len = strlen(token);
                count = 0;
                count2 = 0;

                if(!len) // checking if ethnisity is empty
                {
                    puts("\nWrong input in list, ethnisity can not be empty");
                    return TRUE;
                }

                for(i = 0; i < len; i++) // checking if ethnisity contains invalid characters
                {
                    if(isdigit(token[i]) && !isprint(token[i]) && token[i] != ' ' && token[i] != '(' && token[i] != ')' && token[i] != '.')
                    {
                        puts("\nWrong input in list, ethnisity can not containe numbers");
                        return TRUE;
                    }
                    else if(isalpha(token[i]))
                    {
                        count++;
                    }
                    else
                    {
                        count2++;
                    }
                }

                if(count < count2 && token[0] != '?' && len != 1) // checking if ethnisity contains less letters than other characters
                {
                    puts("\nWrong input in list, ethnisity cant containe less letters than other characters");
                    return TRUE;
                }
             break;

            case 4: // checking gender
                len = strlen(token);

                if(len != 1 && token[0] != 'M' && token[0] != 'F' && token[0] != 'O' && token[0] != 'm' && token[0] != 'f' && token[0] != 'o')
                {
                    puts("\nWrong ipnut in list, gender must be 'O' or 'F' or 'M' and only one character");
                    return TRUE;
                } // checking if gender is valid
             break;

            case 5:
                count = 0;
                count2 = 0;
                count3 = 0;

                len = strlen(token);

                if(!len) // checking if birthdate and birthtime are empty
                {
                    puts("\nWrong input in list, birthdate and birthtime can not be empty");
                    return TRUE;
                }

                for(i = 0; i < len; i++) // checking if birthdate and birthtime contain invalid characters
                {
                    if(isalpha(token[i]) && !isprint(token[i]) && token[i] != '/' && token[i] != ' ' && token[i] != ':')
                    {
                        puts("\nWrong input in list, birthdate and birthtime can not containe letters or special characters");
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

                if(count != 2 || count2 != 1 || count3 != 1) // checking if birthdate and birthtime are valid
                {
                    puts("\nWrong input in list, birthdate and birthtime must have 2 '/' and 1 ' ' and 1 ':'");
                    return TRUE;
                }

                chr = strchr(token, '/');
                chr[0] = '.';
                count = atoi(token);
                count2 = atoi(chr + 1);
                if(count < 1 || count > 31 || count2 < 1 || count2 > 12) // checking if birthdate is valid
                {
                    puts("\nWrong input in list, please enter a valid date");
                    return TRUE;
                }
                else if((count2 == 4 || count2 == 6 || count2 == 9 || count2 == 11) && count > 30)
                {
                    puts("\nWrong input in list, please enter a valid date");
                    return TRUE;
                }

                chr = strchr(token, '/');
                count3 = atoi(chr + 1);

                if(count3 < 1900 || count3 > 2024) // checking if year is valid
                {
                    puts("\nWrong input in list, please enter a valid year");
                    return TRUE;
                }
                else if(count2 == 2 && count > 29 && leapyear(count3)) // checking if year is leap year and if so if february is valid
                {
                    puts("\nWrong input in list, please enter a valid date");
                    return TRUE;
                }
                else if(count2 == 2 && count > 28 && !leapyear(count3)) // checking if year is not leap year and if so if february is valid
                {   
                    puts("\nWrong input in list, please enter a valid date");
                    return TRUE;
                }

                chr = strchr(token, ' ');
                count = atoi(chr + 1);

                if(count < 0 || count > 23) // checking if hour is valid
                {
                    puts("\nWrong input in list, please enter a valid hour");
                    return TRUE;
                }

                chr = strchr(token, ':');
                count = atoi(chr + 1);

                if(count < 0 || count > 59) // checking if minute is valid
                {
                    puts("\nWrong input in list, please enter a valid minute");
                    return TRUE;
                }
             break;

            case 6: // checking networth
                num = atof(token);

                if(num < 0) // checking if networth is valid
                {
                    puts("\nWrong input in list, networth can not be negative");
                    return TRUE;
                }
             break;

            default: // if it has more ';' than it should
                puts("Wrong input in list, too many arguments");
                return TRUE;
        }

        j++;
    }

    if(j != 7) // if it has less ';' than it should
    {
        puts("Wrong input in list, too few arguments");
        return TRUE;
    }

    return FALSE;
}

void check_malloc(void *ptr)
{
    if(ptr == NULL)
    {
        puts("\nError: allocating memory failed");
        exit(EXIT_FAILURE);
    }
}

int check_file(FILE *file)
{
    if(file == NULL)
    {
        puts("\nError: cant open file or file name is incorect\n");
        return TRUE;
    }

    return FALSE;
}

void read_text(char str[], int size, int flag) // Inspired by Mr. Tselikas book
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        puts("\nError reading input");
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
            printf("\nError: too few characters");
            exit(EXIT_FAILURE);
        }
        
        return;
    }

    return;
}

int leapyear(int year)
{
    if(year % 4 != 0)
    {
        return FALSE;
    }
    else if(year % 100 != 0)
    {
        return TRUE;
    }
    else if(year % 400 != 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}