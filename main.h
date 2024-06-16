#ifndef MAIN_H
#define MAIN_H

#define MAX_SIZE 200 // acts as a buffer for the input
#define TRUE 1 
#define FALSE 0
#define BONUS TRUE
#define CHAR_SIZE sizeof(char)
#define LIST_SIZE sizeof(billionare)

typedef struct
{
    int year;
    int month;
    int day;
}mydate;

typedef struct
{
    int hour;
    int minutes;
}mytime;

typedef struct
{
    int namelen;
    char *name;
    int ethnicitylen;
    char *ethnisity;
    char gender;
    float networth;
    char *bank;
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
    mydate birthdate;
    mytime birthtime;
    identity id;
    corperate corp;
    struct billist *next;
    struct billist *prev;

}billionare;

extern billionare *head;

#endif