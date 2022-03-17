#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 20


void echo (char * str){
    memcpy(str,str+5,MAX_LIMIT-4);
    printf(str);
}


int main (){

    char str[MAX_LIMIT] = "on";
    int flag = 1 , rst;
    char exit[5]="EXIT";
    while (strncmp(str,exit,4) != 0 ){
        printf("yes master : ");
       fgets(str,MAX_LIMIT,stdin);
        if (strncmp (str,"ECHO", 4) == 0){
            echo(str);
        }
        


    }

    printf("\nbye bye \n");

}


