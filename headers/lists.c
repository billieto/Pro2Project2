#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "inputnfiles.h"
#include "lists.h"

void print(char ch, char *str)
{
    billionare *temp = head;
    int len = 0, i = 0;
    char print = '\0';
    char *token = NULL, *token2 = NULL, *token3 = NULL;

    if(check_list_empty(head))
    {
        return;
    }

    if((token = strtok(str, "/")) != NULL) // Na tsekarw gia to an exei mono hmerominia kai wra, na to kanw panw sto read_input
    {
        print = '/';
        token2 = strtok(NULL, "/");
        token3 = strtok(NULL, "/");
    }
    else if((token = strtok(str, ":")) != NULL)
    {
        token2 = strtok(NULL, ":");
        print = ':';
    }
    else
    {
        print = '\0';
    }

    switch(ch)
    {
        case '+':
            switch(print)
            {
                case '/':
                    while(TRUE)
                    {
                        if((temp -> birthdate.year > atoi(token3)))
                        {
                            simple_print(temp);
                        }
                        else if(temp -> birthdate.year == atoi(token3) && temp -> birthdate.month > atoi(token2))
                        {
                            simple_print(temp);
                        }
                        else if(temp -> birthdate.year == atoi(token3) && temp -> birthdate.month == atoi(token2) && temp -> birthdate.day > atoi(token))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                case ':':
                    while(TRUE)
                    {
                        if((temp -> birthtime.hour > atoi(token)))
                        {
                            simple_print(temp);
                        }
                        else if(temp -> birthtime.hour == atoi(token) && temp -> birthtime.minutes > atoi(token2))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                default:
                    while(TRUE)
                    {
                        if(temp -> id.networth > atof(str))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
            }
         break;

        case '-':
            switch(print)
            {
                case '/':
                    while(TRUE)
                    {
                        if((temp -> birthdate.year < atoi(token)))
                        {
                            simple_print(temp);
                        }
                        else if(temp -> birthdate.year == atoi(token) && temp -> birthdate.month < atoi(token2))
                        {
                            simple_print(temp);
                        }
                        else if(temp -> birthdate.year == atoi(token) && temp -> birthdate.month == atoi(token2) && temp -> birthdate.day < atoi(token3))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                case ':':
                    while(TRUE)
                    {
                        if((temp -> birthtime.hour < atoi(token)))
                        {
                            simple_print(temp);
                        }
                        else if(temp -> birthtime.hour == atoi(token) && temp -> birthtime.minutes < atoi(token2))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                default:
                    while(TRUE)
                    {
                        if(temp -> id.networth < atof(str))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
            }
         break;
        
        case '=':
            switch(print)
            {
                case '/':
                    while(TRUE)
                    {
                        if((temp -> birthdate.day == atoi(token)) && temp -> birthdate.month == atoi(token2) && temp -> birthdate.year == atoi(token3))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                case ':':
                    while(TRUE)
                    {
                        if((temp -> birthtime.hour == atoi(token)) && (temp -> birthtime.hour == atoi(token2)))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                default:
                    while(TRUE)
                    {
                        if(temp -> id.networth == atof(str))
                        {
                            simple_print(temp);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
            }
         break;
    }
}

void find(char ch, char *str)
{
    billionare *temp = head;
    int flag = FALSE, len = 0, i = 0;
    char *chr = NULL;

    if(check_list_empty(head))
    {
        return;
    }

    len = strlen(str);

    if(len == 1 && str[0] == '*')
    {
        ch = '*';
    }
    else
    {
        for(i = 0; i < len; i++)
        {
            if(isupper(str[i]))
            {
                str[i] = tolower(str[i]);
            }
        }
    }
    
    switch(ch)
    {
        case 'N':
            while(TRUE)
            {
                temp -> id.name[0] = tolower(temp -> id.name[0]);
                chr = strchr(temp -> id.name, ' ');
                chr[1] = tolower(chr[1]);

                if((chr = strstr(temp -> id.name, "jr")) != NULL)
                {
                    chr[0] = tolower(chr[0]);
                }

                if((chr = strchr(temp -> id.name, '-')) != NULL)
                {
                    chr[1] = tolower(chr[1]);
                }

                if((strstr(temp -> id.name, str) != NULL))
                {
                    flag = TRUE;
                }

                temp -> id.name[0] = toupper(temp -> id.name[0]);
                chr = strchr(temp -> id.name, ' ');
                chr[1] = toupper(chr[1]);

                if((chr = strstr(temp -> id.name, "jr")) != NULL)
                {
                    chr[0] = toupper(chr[0]);
                }

                if((chr = strchr(temp -> id.name, '-')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }

                if(flag)
                {
                    simple_print(temp);
                    flag = FALSE;
                }

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
         break;

        case 'C':
            while(TRUE)
            {
                temp -> corp.city[0] = tolower(temp -> corp.city[0]);
                temp -> corp.country[0] = tolower(temp -> corp.country[0]);

                if((strstr(temp -> corp.city, str) != NULL) || (strstr(temp -> corp.country, str) != NULL))
                {
                    flag = TRUE;
                }

                temp -> corp.city[0] = toupper(temp -> corp.city[0]);
                temp -> corp.country[0] = toupper(temp -> corp.country[0]);

                if(flag)
                {
                    simple_print(temp);
                    flag = FALSE;
                }

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
         break;

        case 'S':
            while(TRUE)
            {
                temp -> corp.source[0] = tolower(temp -> corp.source[0]);
                while((chr = strchr(temp -> corp.source, ' ')) != NULL)
                {
                    chr[1] = tolower(chr[1]);
                }

                if((strstr(temp -> corp.source, str) != NULL))
                {
                    flag = TRUE;
                }

                temp -> corp.source[0] = toupper(temp -> corp.source[0]);
                while((chr = strchr(temp -> corp.source, ' ')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }

                if(flag)
                {
                    simple_print(temp);
                    flag = FALSE;
                }

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
         break;

         case '*':
            while(TRUE)
            {
                simple_print(temp);

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
          break;
    }
}

void delete(char ch)
{
    billionare *temp = head;

    if(check_list_empty(head))
    {
        puts("Nothing to delete");
        return;
    }

    switch(ch)
    {
        case 'N':
            temp = head -> prev;
            temp -> prev -> next = head;
            head -> prev = temp -> prev;
            free(temp -> id.name);
            free(temp -> corp.city);
            free(temp -> corp.country);
            free(temp -> corp.source);
            free(temp -> id.ethnisity);
            free(temp);
            if(head == temp)
            {
                head = NULL;
            }
         break;

        case 'O':
            temp = head -> next;
            temp -> prev = head -> prev;
            head -> prev -> next  = temp;
            free(head -> id.name);
            free(head -> corp.city);
            free(head -> corp.country);
            free(head -> corp.source);
            free(head -> id.ethnisity);
            free(head);
            if(head == temp)
            {
                head = NULL;
            }
            else
            {
                head = temp;
            }
         break;
    }
}

void simple_print(billionare *temp)
{
    printf("\nName: %s\n", temp -> id.name);
    printf("City: %s\n", temp -> corp.city);
    printf("Country: %s\n", temp -> corp.country);
    printf("Source: %s\n", temp -> corp.source);
    printf("Ethnicity: %s\n", temp -> id.ethnisity);
    printf("Gender: %c\n", temp -> id.gender);
    printf("Birthdate: %d/%d/%d\n", temp -> birthdate.day, temp -> birthdate.month, temp -> birthdate.year);
    if(temp -> birthtime.hour < 10 && temp -> birthtime.minutes < 10)
    {
        printf("Birthtime: 0%d:0%d\n", temp -> birthtime.hour, temp -> birthtime.minutes);
    }
    else if(temp -> birthtime.hour < 10)
    {
        printf("Birthtime: 0%d:%d\n", temp -> birthtime.hour, temp -> birthtime.minutes);
    }
    else if(temp -> birthtime.minutes < 10)
    {
        printf("Birthtime: %d:0%d\n", temp -> birthtime.hour, temp -> birthtime.minutes);
    }
    else
    {
        printf("Birthtime: %d:%d\n", temp -> birthtime.hour, temp -> birthtime.minutes);
    }
    printf("Networth: %.1f\n", temp -> id.networth);
}

void sum(void)
{
    billionare *temp = head;
    double sum = 0;

    if(check_list_empty(head))
    {
        return;
    }

    while(TRUE)
    {
        sum += temp -> id.networth;

        temp = temp -> next;

        if(temp == head)
        {
            break;
        }
    }

    printf("The sum of all networths is: %.2f\n", sum);

}

void write_node(char *str)
{
    billionare *last = NULL, *new = NULL;
    int i = 0;
    char *str2 = NULL, *token = NULL, *chr = NULL;

    if (head != NULL)
    {
        last = head -> prev;
    }
    
    new = (billionare*) malloc(LIST_SIZE);
    check_malloc(new);

    while((token = strtok(str, ";")) != NULL)
    {
        switch(i)
        {
            case 0:
                u_inisialize(&(new -> id.name), &(new -> id.namelen), token);

                if((chr = strchr(new -> id.name, ' ')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                    if(((chr = strchr((chr + 1), ' ')) != NULL) && chr[1] != '&')
                    {
                        chr[1] = toupper(chr[1]);
                    }
                }

                if((chr = strstr(new -> id.name, "jr")) != NULL)
                {
                    chr[0] = toupper(chr[0]);
                }

                if((chr = strchr(new -> id.name, '-')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }

                str = NULL;
             break;

            case 1:
                
                chr = strchr(token, '/');
                chr[0] = '\0';
                
                if(token[0] == '?')
                {
                    inisialize(&new -> corp.city, &new -> corp.citylen, "Unknown");
                }
                else
                {
                    inisialize(&new -> corp.city, &new -> corp.citylen, token);
                }

                if(token[0] == '?')
                {
                    inisialize(&new -> corp.country, &new -> corp.countrylen, "Unknown");
                }
                else
                {
                    inisialize(&new -> corp.country, &new -> corp.countrylen, (chr + 1));

                    if((chr = strchr(new -> corp.country, ' ')) != NULL)
                    {
                        if(chr[1] == '(')
                        {
                            chr[2] = toupper(chr[2]);
                        }
                        else
                        {
                            chr[1] = toupper(chr[1]);
                        }
                    }
                }
             break;

            case 2:
                u_inisialize(&new -> corp.source, &new -> corp.sourcelen, token);

                if((chr = strchr(new -> corp.source, ' ')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }
             break;

            case 3:
                inisialize(&new -> id.ethnisity, &new -> id.ethnicitylen, token);

                if((chr = strchr(new -> id.ethnisity, ' ')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }
             break;

            case 4:
                new -> id.gender = token[0];
             break;

            case 5:
                sscanf(token, "%d/%d/%d %d:%d", &new -> birthdate.day, &new -> birthdate.month, &new -> birthdate.year, &new -> birthtime.hour, &new -> birthtime.minutes);
             break;

            case 6:
                new -> id.networth = atof(token);
             break;
        }

        i++;
    }

    if(head == NULL)
        {
            head = new;
            new -> next = new;
            new -> prev = new;
        }
        else
        {
            new -> next = head;
            new -> prev = last;
            last -> next = new;
            head -> prev = new;
        }
}

void u_inisialize(char **str, int *len, char *token)
{
    *len = strlen(token);
    *str = (char*) malloc((*len + 1) * CHAR_SIZE);
    check_malloc(*str);
    strcpy(*str, token);

    right_input(*str);
}

void inisialize(char **str, int *len, char *token)
{
    *len = strlen(token);
    *str = (char*) malloc((*len + 1) * CHAR_SIZE);
    check_malloc(*str);
    strcpy(*str, token);

    right_input(*str);
}

void free_list(void)
{
    billionare *temp = head, *next = NULL;

    if(check_list_empty(head))
    {
        return;
    }

    while(TRUE)
    {
        next = temp -> next;
        free(temp -> id.name);
        free(temp -> corp.city);
        free(temp -> corp.country);
        free(temp -> corp.source);
        free(temp -> id.ethnisity);
        free(temp);

        temp = next;

        if(temp == head)
        {
            break;
        }
    }

    head = NULL;
}