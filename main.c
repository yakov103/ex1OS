#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include "client.h"
#include <sys/wait.h> // for wait()

/*
 *A. do loop for yes master - DONE !!!!!!!!!!!!!!!!!
 *B.Read getCWD  - DONE !!!!!!!!!!!!!!!!!!!
 *C. ECHO - DONE !!!!!!!!!!!!!!!!!!!
 *D.1 TCP PORT - ?
 *D.2 server - ?
 *E. LOCAL - ?
 *F. DIR - DONE !!!!!!!!!!!!!!!!!!!!
 *G. CD - DONE  -- not working with system
 *H. add system methods -- add some comments .
 *I. implemnt with frok(), exec(), wait ()- ?
 *J. COPY SRC DEST - make a copy of file - ?
 *K. DELETE function - delete file - ?
 */

#define MAX_LIMIT PATH_MAX

void dir(char str[MAX_LIMIT]);
void echo(char *str);
void cd(char *str);
void fork_echo();

// https://www.tutorialspoint.com/c_standard_library/c_function_system.htm

int main(int argc, char const *argv[])
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
    char exit[5] = "EXIT";
    while (strncmp(str, exit, 4) != 0)
    {
        printf("yes master : ");
        fgets(str, MAX_LIMIT, stdin);
        if (strncmp(str, "ECHO", 4) == 0)
        {
            // our function **********************
            // echo(str);
            // sysem function ********************
            // str[0] = 'e';
            // str[1] = 'c';
            // str[2] = 'h';
            // str[3] = 'o';
            // system(str);
            // fork wait and execv ***************
        }
        else if (strncmp(str, "DIR", 3) == 0)
        {
            // our function **********************
            // dir(str);
            // sysem function ********************
            // str[0] = 'd';
            // str[1] = 'i';
            // str[2] = 'r';
            // system(str);
            // fork wait and execv ***************
        }
        else if (strncmp(str, "CD", 2) == 0)
        {
            // our function ****************************
            // cd(str);
            // sysem function **************************
            // str[0] = 'c';
            // str[1] = 'd';
            // system(str);
            // if (getcwd(cwd, sizeof(cwd)) != NULL)
            // {
            //     printf("Current working dir: %s\n", cwd);
            // }
            // else
            // {
            //     perror("getcwd() error");
            // }
            // fork wait and execv *********************
            fork_echo();
        }
        else if (strncmp(str, "TCP PORT", 8) == 0)
        {
            client();
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

void cd(char *str)
{
    memcpy(str, str + 3, MAX_LIMIT - 3);
    int counter = strlen(str);
    char str3[counter];
    memcpy(str3, str, counter - 1);
    // printf("str3:  %s", str3);
    printf("%s", str);
    chdir(str3);
    // printing current working directory
    printf("%s\n", getcwd(str, 100));
}

void fork_echo(char *path_to_dir, int size)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        // error, failed to fork()
        perror("can't fork");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        printf("status: %d", status);
    }
    else
    {
        // we are the child
        char *bin_path = "/bin/dir";
        char *args[] = {bin_path, NULL};
        execv(bin_path, args);
    }
}