#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "inputnfiles.h"
#include "lists.h"

void print(char ch, char *str, char print)
{
    billionare *temp = head;
    int flag = FALSE, num = 0, num2 = 0, num3 = 0;
    char *token = NULL, *token2 = NULL, *token3 = NULL;

    if(check_list_empty(head))
    {
        return;
    }

    switch(print) // cuts the string into pieces so we can compare them, default is networth
    {
        case '/':
            token = strtok(str, "/");
            token2 = strtok(NULL, "/");
            token3 = strtok(NULL, "/");

            num = atoi(token);
            num2 = atoi(token2);
            num3 = atoi(token3);
         break;

        case ':':
            token = strtok(str, ":");
            token2 = strtok(NULL, ":");

            num = atoi(token);
            num2 = atoi(token2);
         break;
    }

    switch(ch)
    {
        case '+': // print above
            switch(print)
            {
                case '/': // birthdate
                    while(TRUE)
                    {
                        if((temp -> birthdate.year > num3))
                        {
                            simple_print(temp, &flag);
                        }
                        else if(temp -> birthdate.year == num3 && temp -> birthdate.month > num2)
                        {
                            simple_print(temp, &flag);
                        }
                        else if(temp -> birthdate.year == num3 && temp -> birthdate.month == num2 && temp -> birthdate.day > num)
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                case ':': // birthtime
                    while(TRUE)
                    {
                        if((temp -> birthtime.hour > num))
                        {
                            simple_print(temp, &flag);
                        }
                        else if(temp -> birthtime.hour == num && temp -> birthtime.minutes > num2)
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                default: // networth
                    while(TRUE)
                    {
                        if(temp -> id.networth > atof(str))
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
            }
         break;

        case '-': // print below
            switch(print)
            {
                case '/': // birthdate
                    while(TRUE)
                    {
                        if((temp -> birthdate.year < num))
                        {
                            simple_print(temp, &flag);
                        }
                        else if(temp -> birthdate.year == num && temp -> birthdate.month < num2)
                        {
                            simple_print(temp, &flag);
                        }
                        else if(temp -> birthdate.year == num && temp -> birthdate.month == num2 && temp -> birthdate.day < num3)
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                case ':': // birthtime
                    while(TRUE)
                    {
                        if((temp -> birthtime.hour < num))
                        {
                            simple_print(temp, &flag);
                        }
                        else if(temp -> birthtime.hour == num && temp -> birthtime.minutes < num2)
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                default: // networth
                    while(TRUE)
                    {
                        if(temp -> id.networth < atof(str))
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
            }
         break;
        
        case '=': // print equal
            switch(print)
            {
                case '/': // birthdate
                    while(TRUE)
                    {
                        if((temp -> birthdate.day == num) && temp -> birthdate.month == num2 && temp -> birthdate.year == num3)
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                case ':': // birthtime
                    while(TRUE)
                    {
                        if((temp -> birthtime.hour == num) && (temp -> birthtime.minutes == num2))
                        {
                            simple_print(temp, &flag);
                        }

                        temp = temp -> next;

                        if(temp == head)
                        {
                            break;
                        }
                    }
                 break;

                default: // networth
                    while(TRUE)
                    {
                        if(temp -> id.networth == atof(str))
                        {
                            simple_print(temp, &flag);
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
    int len = 0, flag2 = FALSE; // flag2 is used to print the header of simple_print() only once
    char *mal = NULL, *mal2 = NULL;

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
        all_lower(str, len); 
    }
    
    switch(ch)
    {
        case 'N': // name
            while(TRUE)
            {
                mal = strdup(temp -> id.name);
                check_malloc(mal);

                all_lower(mal, temp -> id.namelen);

                if((strstr(mal, str) != NULL))
                {
                    simple_print(temp, &flag2);
                }

                free(mal);

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
         break;

        case 'C': // city and country
            while(TRUE)
            {
                mal = strdup(temp -> corp.city);
                check_malloc(mal);

                mal2 = strdup(temp -> corp.country);
                check_malloc(mal2);

                all_lower(mal, temp -> corp.citylen);

                all_lower(mal2, temp -> corp.countrylen);

                if((strstr(mal, str) != NULL) || (strstr(mal2, str) != NULL))
                {
                    simple_print(temp, &flag2);
                }

                free(mal);
                free(mal2);

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
         break;

        case 'S': // source
            while(TRUE)
            {
                mal = strdup(temp -> corp.source);
                check_malloc(mal);

                all_lower(mal, temp -> corp.sourcelen);

                if((strstr(mal, str) != NULL))
                {
                    simple_print(temp, &flag2);
                }

                free(mal);

                temp = temp -> next;

                if(temp == head)
                {
                    break;
                }
            }
         break;

         case '*': // prints all
            while(TRUE)
            {
                simple_print(temp, &flag2);

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
    billionare *temp = NULL;

    if(check_list_empty(head))
    {
        return;
    }

    if(head -> prev == head) // if there is only one node
    {
        free(head -> id.name);
        free(head -> corp.city);
        free(head -> corp.country);
        free(head -> corp.source);
        free(head -> id.ethnisity);
        free(head -> id.bank);
        free(head);
        head = NULL;
        return;
    }

    switch(ch)
    {
        case 'N': // delete the first node
            temp = head -> prev -> prev;
            temp -> next = head;
            free(head -> prev -> id.name);
            free(head -> prev -> corp.city);
            free(head -> prev -> corp.country);
            free(head -> prev -> corp.source);
            free(head -> prev -> id.ethnisity);
            free(head -> prev -> id.bank);
            free(head -> prev);
            head -> prev = temp;
         break;

        case 'O': // delete the last node
            temp = head;
            head = head -> next;
            head -> prev = temp -> prev;
            head -> prev -> next = head;
            free(temp -> id.name);
            free(temp -> corp.city);
            free(temp -> corp.country);
            free(temp -> corp.source);
            free(temp -> id.ethnisity);
            free(temp -> id.bank);
            free(temp);
         break;
    }
}

void simple_print(billionare *temp, int *flag)
{
    int i;
    
    if(!(*flag)) // prints the header only once
    {
        *flag = TRUE;
        printf("\n%-40s %-25s %-30s %-35s %-20s %-2s %-10s %-7s %-10s\n",
                "Name", "City", "Country", "Source", "Ethnicity", "G", "Birth Date n Time", "Net", "Bank account number");
    }
        //  name  city  country,source,ethnisity,gender 
    printf("%-40s %-25s %-30s %-35s %-20s %-2c ",
            temp -> id.name, temp -> corp.city, temp -> corp.country, temp -> corp.source, temp -> id.ethnisity, temp -> id.gender);
    
    printf("%02d/%02d/%d ", temp -> birthdate.day, temp -> birthdate.month, temp -> birthdate.year);
    
    printf("%02d:%02d", temp -> birthtime.hour, temp -> birthtime.minutes);

    printf("\t%.1f\t", temp -> id.networth);

    for(i = 0; i < 11; i++)
    {
        printf("%d", temp -> id.bank[i]);
    }

    putchar('\n');
}

double sum(void)
{
    billionare *temp = head;
    double sum = 0;

    if(check_list_empty(head))
    {
        return 0;
    }

    while(TRUE) // sums the networth of all the billionares
    {
        sum += temp -> id.networth;

        temp = temp -> next;

        if(temp == head)
        {
            break;
        }
    }

    return sum;
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

    token = strdup(str); 
    check_malloc(token);

    if(check_input(token)) // checks if the input is valid with a duplicate of the original string so i can modify it without losing the original
    {
        free(token);
        return;
    }

    free(token);
    
    new = (billionare*) malloc(LIST_SIZE);
    check_malloc(new);

    while((token = strtok(str, ";")) != NULL)
    {
        switch(i)
        {
            case 0: // inisializing the name
                inisialize(&(new -> id.name), &(new -> id.namelen), token);

                if((chr = strchr(new -> id.name, ' ')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                    while(((chr = strchr((chr + 1), ' ')) != NULL) && chr[1] != '&')
                    {
                        chr[1] = toupper(chr[1]);
                    }
                }

                if((chr = strstr(new -> id.name, "jr")) != NULL)
                {
                    chr[0] = toupper(chr[0]);
                }

                if((chr = strchr(new -> id.name, '-')) != NULL && new -> id.namelen >= 2)
                {
                    chr[1] = toupper(chr[1]);
                }

                if((chr = strchr(new -> id.name, '(')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }

                if((chr = strchr(new -> id.name, '.')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                    while(((chr = strchr((chr + 1), '.')) != NULL))
                    {
                        chr[1] = toupper(chr[1]);
                    }
                }

                if((chr = strchr(new -> id.name, '\'')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                }

                str = NULL;
             break;

            case 1: // inisializing the city and country
                
                chr = strchr(token, '/');
                chr[0] = '\0';
                str2 = chr + 1;
                
                if(token[0] == '?')
                {
                    inisialize(&new -> corp.city, &new -> corp.citylen, "Unknown");
                }
                else
                {
                    inisialize(&new -> corp.city, &new -> corp.citylen, token);
                    
                    if((chr = strchr(new -> corp.city, ' ')) != NULL)
                    {
                        chr[1] = toupper(chr[1]);
                        while(((chr = strchr((chr + 1), ' ')) != NULL))
                        {
                            chr[1] = toupper(chr[1]);
                        }
                    }
                }

                
                if(str2[0] == '?')
                {
                    inisialize(&new -> corp.country, &new -> corp.countrylen, "Unknown");
                }
                else
                {
                    inisialize(&new -> corp.country, &new -> corp.countrylen, str2);

                    if((chr = strchr(new -> corp.country, ' ')) != NULL)
                    {
                        chr[1] = toupper(chr[1]);
                        while(((chr = strchr((chr + 1), ' ')) != NULL))
                        {
                            chr[1] = toupper(chr[1]);
                        }
                    }

                    if((chr = strchr(new -> corp.country, '(')) != NULL)
                    {
                        chr[1] = toupper(chr[1]);
                    }
                }
             break;

            case 2: // inisializing the source
                inisialize(&new -> corp.source, &new -> corp.sourcelen, token);

                if((chr = strchr(new -> corp.source, ' ')) != NULL)
                {
                    chr[1] = toupper(chr[1]);
                    while(((chr = strchr((chr + 1), ' ')) != NULL) && chr[1] != '&')
                    {
                        chr[1] = toupper(chr[1]);
                    }
                }
             break;

            case 3: // inisializing the ethnisity
                if(token[0] == '?')
                {
                    inisialize(&new -> id.ethnisity, &new -> id.ethnicitylen, "Unknown");
                }
                else
                {
                    inisialize(&new -> id.ethnisity, &new -> id.ethnicitylen, token);
                    if((chr = strchr(new -> id.ethnisity, ' ')) != NULL)
                    {
                        chr[1] = toupper(chr[1]);
                    }
                }
             break;

            case 4: // inisialiazing the gender
                if(isupper(token[0]))
                {
                    new -> id.gender = token[0];
                }
                else
                {
                    new -> id.gender = tolower(token[0]);
                }
             break;

            case 5: // inisializing the birthdate and birthtime
                sscanf(token, "%d/%d/%d %d:%d", &new -> birthdate.day, &new -> birthdate.month, &new -> birthdate.year, &new -> birthtime.hour, &new -> birthtime.minutes);
             break;

            case 6: // inisializing the networth
                new -> id.networth = atof(token);
             break;
        }

        i++;
    }

    bank_account(new); // inisializing the bank account number

    if(head == NULL) // keeping the list circular and doubly linked
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

void inisialize(char **str, int *len, char *token)
{
    *len = strlen(token);
    *str = strdup(token);
    check_malloc(*str);

    right_input(*str);
}

void free_list(void)
{
    billionare *temp = head, *next = NULL;

    if(check_list_empty(head))
    {
        return;
    }

    while(TRUE) // frees all the memory allocated
    {
        next = temp -> next;
        free(temp -> id.name);
        free(temp -> corp.city);
        free(temp -> corp.country);
        free(temp -> corp.source);
        free(temp -> id.ethnisity);
        free(temp -> id.bank);
        free(temp);

        temp = next;

        if(temp == head)
        {
            break;
        }
    }

    head = NULL;
}

int check_list_empty(billionare *head)
{
    if(head == NULL)
    {
        puts("\nList is empty cannot do any operation");
        puts("First load billionares from file or add a new one");
        return TRUE;
    }

    return FALSE;
}

void bank_account(billionare *new)
{
    int i, checkdigit, checkdigit_finder[10], flag = TRUE;
    double d;
    billionare *temp = head;

    new -> id.bank = (int*) malloc(11 * INT_SIZE);
    check_malloc(new -> id.bank);

    while(flag == TRUE)
    {
        flag = FALSE;

        for(i = 0; i < 10; i++)
        {
            d = (double) rand() / ((double) RAND_MAX + 1);
            d = d * 9;
            new -> id.bank[i] = (int) d + 1;
        }

        for(i = 1; i < 10; i += 2)
        {
            checkdigit_finder[i] = new -> id.bank[i];
            checkdigit_finder[i] *= 2;

            if(checkdigit_finder[i] > 9)
            {
                checkdigit_finder[i] = checkdigit_finder[i] / 10 + checkdigit_finder[i] % 10;
            }

            checkdigit += checkdigit_finder[i];
        }

        checkdigit *= 9;
        checkdigit %= 10;

        new -> id.bank[10] = checkdigit;

        while(temp != head)
        {
            if(!memcmp(new -> id.bank, temp -> id.bank, 11 * INT_SIZE))
            {
                flag = TRUE;
                break;
            }

            temp = temp -> next;
        }
    }
}

void all_lower(char *str, int len)
{
    int i;

    for(i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}