#ifndef MAIN_H
#define MAIN_H

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

extern billionare *head;

#endif