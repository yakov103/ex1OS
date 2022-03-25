#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#define MAX_LIMIT PATH_MAX

void dir(char str[MAX_LIMIT]);
void echo(char *str);

// https://www.tutorialspoint.com/c_standard_library/c_function_system.htm

int main()
{
    // https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Current working dir: %s\n", cwd);
    }
    else
    {
        perror("getcwd() error");
    }

    char str[MAX_LIMIT] = "on";
    int flag = 1, rst;
    char exit[5] = "EXIT";
    while (strncmp(str, exit, 4) != 0)
    {
        printf("yes master : ");
        fgets(str, MAX_LIMIT, stdin);
        if (strncmp(str, "ECHO", 4) == 0)
        {
            echo(str);
        }
        else if (strncmp(str, "DIR", 3) == 0)
        {
            dir(str);
        }
        else if (strncmp(str, "CD", 2) == 0)
        {
            
            memcpy(str, str + 3, MAX_LIMIT - 3);
            printf("%s", str);

            // chdir זה פונקציית מערכת כי היא מבקשת מהמערכת ההפעלה לשנות את המקום של התהליך
            // char str2[MAX_LIMIT];
            // strncpy(str2, str + 2, MAX_LIMIT - 2);
            // printf("%s\n", str2);
            // int counter1 = 0;
            // printf("%c", (str[3 + counter1]));
            // printf("\n");
            // while (str[3 + counter1] != '\0')
            // {
            //     counter1++;
            // }
            // counter1--;
            // printf("%d" , counter1);
            // printf("%c", (str[3 + counter1]));

            // // chdir(str2);
            // // /home/dolev2004/Documents/dick
            chdir(str);
            // printing current working directory
            printf("%s\n", getcwd(str, 100));
        }
    }

    printf("\nbye bye \n");
}

void dir(char str[MAX_LIMIT])
{
    DIR *dir;
    struct dirent *pdir;
    dir = opendir(".");
    if (dir == NULL)
    {
        printf("Error with reading ");
        return;
    }
    while ((pdir = readdir(dir)) != NULL)
    {
        if (pdir->d_name[0] != '.')
        {
            printf("%s\t", pdir->d_name);
        }
    }
    printf("\n");
    closedir(dir);
}

void echo(char *str)
{
    memcpy(str, str + 5, MAX_LIMIT - 4);
    printf("%s", str);
}
