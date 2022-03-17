#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define MAX_LIMIT 20


void dir(char str[MAX_LIMIT]);
void echo (char * str);



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
        else if (strncmp(str,"DIR",3)== 0){
            dir(str);

        }
        


    }

    printf("\nbye bye \n");

}

void dir(char str[MAX_LIMIT]) {
    DIR *dir ;
    struct dirent *pdir;
    dir = opendir(".");
    if ( dir == NULL) {
        printf("Error with reading ");
        return;
    }
    while ((pdir = readdir(dir)) != NULL){
        if (pdir->d_name[0] != '.')
        {
            printf("%s\t", pdir->d_name);
        }
    }
    printf("\n");
    closedir(dir);
    }

void echo (char * str){
    memcpy(str,str+5,MAX_LIMIT-4);
    printf(str);
}


