#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef struct people {
    char name[SIZE];
    char ID[SIZE];
    char password[SIZE];
} People;

extern int idline, passline;
extern People s2;

void get_infor(People* s);
int infor_ID(char* ID);
int infor_password(char* password, char* ID);
void sign_up();
void login();

#endif // USER_MANAGEMENT_H
