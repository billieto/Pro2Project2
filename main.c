#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//typedef unsigned char char;

#define MAX_SIZE 200
#define TRUE 1
#define FALSE 0
#define CHAR_SIZE sizeof(char)
#define LIST_SIZE sizeof(billionare)
//#define UCHAR_SIZE sizeof(unsigned char)

typedef struct
{
    int year;
    int month;
    int day;
}date;

typedef struct
{
    int hour;
    int minutes;
}time;

typedef struct
{
    int namelen;
    char *name;
    int ethnicitylen;
    char *ethnisity;
    char gender;
    float networth;
    int *bank;
}identity;

typedef struct 
{
    int sourcelen;
    char *source;
    int citylen;
    char *city;
    int countrylen;
    char *country;
}corperate;

typedef struct billist
{
    date birthdate;
    time birthtime;
    identity id;
    corperate corp;
    struct billist *next;
    struct billist *prev;

}billionare;

billionare *head = NULL;

void load(char *filename, int input);
void save(char *filename, int input);
void write_node(char *str);
void free_list(void);
void find(char ch, char *str);
void print(char ch, char *str);
void delete(char ch);
void inisialize(char **str, int *len, char *token);
void u_inisialize(char **str, int *len, char *token);
void sum(void);
void simple_print(billionare *temp);
int check_list_empty(billionare *head);
void check_malloc(void *ptr);
int check_input(char *str);
int check_file(FILE *file);
int read_text(char str[], int size, int flag);
int isalphabetic(char ch);
void right_input(char *str);

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

int isalphabetic(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= 199 && ch <= 255))
    {
        return TRUE;
    }

    return FALSE;
}

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