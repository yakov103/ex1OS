#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include "client.h"
#include <sys/wait.h> // for wait()
#include <ctype.h>

/*
 *A. do loop for yes master - DONE !!!!!!!!!!!!!!!!!
 *B.Read getCWD  - DONE !!!!!!!!!!!!!!!!!!!
 *C. ECHO - DONE !!!!!!!!!!!!!!!!!!!
 *D.1 TCP PORT - DONE
 *D.2 server - DONE
 *E. LOCAL - DONE
 *F. DIR - DONE !!!!!!!!!!!!!!!!!!!!
 *G. CD - DONE  -- not working with system
 *H. add system methods -- DONE
 *I. implemnt with fork(), exec(), wait ()- DONE
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
    char exit_program[5] = "EXIT";
    while (strncmp(str, exit_program, 4) != 0)
    {
        printf("yes master : ");
        fgets(str, MAX_LIMIT, stdin);
        if (strncmp(str, "ECHO", 4) == 0)
        {
            // our function **********************
            echo(str);
            // sysem function ********************
            // str[0] = 'e';
            // str[1] = 'c';
            // str[2] = 'h';
            // str[3] = 'o';
            // system(str);
            // fork wait and execv ***************
            // memcpy(str, str + 5, MAX_LIMIT - 4);
            // pid_t pid = fork();
            // if (pid == -1)
            // {
            //     // error, failed to fork()
            //     perror("can't fork");
            //     exit(1);
            // }
            // else if (pid > 0)
            // {
            //     int status;
            //     waitpid(pid, &status, 0);
            //     printf("status: %d", status);
            // }
            // else
            // {
            //     // we are the child
            //     char *bin_path = "/bin/echo";
            //     char *args[] = {bin_path, str};
            //     execv(bin_path, args);
            // }
        }
        else if (strncmp(str, "DIR", 3) == 0)
        {
            // our function **********************
            dir(str);
            // sysem function ********************
            // str[0] = 'd';
            // str[1] = 'i';
            // str[2] = 'r';
            // system(str);
            // fork wait and execv ***************
            // pid_t pid = fork();
            // if (pid == -1)
            // {
            //     // error, failed to fork()
            //     perror("can't fork");
            //     exit(1);
            // }
            // else if (pid > 0)
            // {
            //     int status;
            //     waitpid(pid, &status, 0);
            //     printf("status: %d", status);
            // }
            // else
            // {
            //     // we are the child
            //     char *bin_path = "/bin/dir";
            //     char *args[] = {bin_path, NULL};
            //     execv(bin_path, args);
            // }
        }
        else if (strncmp(str, "CD", 2) == 0)
        {
            // our function ****************************
            cd(str);
            // sysem function **************************
            // not working because it run the function on the child process
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
            // not working because it run the function on the child process
            // memcpy(str, str + 3, MAX_LIMIT - 3);
            // pid_t pid = fork();
            // if (pid == -1)
            // {
            //     // error, failed to fork()
            //     perror("can't fork");
            //     exit(1);
            // }
            // else if (pid > 0)
            // {
            //     int status;
            //     waitpid(pid, &status, 0);
            //     printf("status: %d", status);
            //     if (getcwd(cwd, sizeof(cwd)) != NULL)
            //     {
            //         printf("Current working dir: %s\n", cwd);
            //     }
            //     else
            //     {
            //         perror("getcwd() error");
            //     }
            // }
            // else
            // {
            //     // we are the child
            //     char *bin_path = "/bin/cd";
            //     char *args[] = {bin_path, str};
            //     execv(bin_path, args);
            // }
        }
        else if (strncmp(str, "TCP PORT", 8) == 0)
        {
            client();
        }
        else if (strncmp(str, "DELETE", 6) == 0)
        {
            memcpy(str, str + 7, MAX_LIMIT - 7);
            char *word;
            char *src_str;
            src_str = strtok(str, " ");
            printf("%s", src_str);
            int res;
            res = unlink(src_str);
            if (res != 0){
                printf("problem delete\n");
            }
            // remove(src_str);  also not working 
        }
        else if (strncmp(str, "COPY", 4) == 0)
        {
            memcpy(str, str + 5, MAX_LIMIT - 5);
            char *word;
            char *src_str;
            char *dest_str;
            src_str = strtok(str, " ");
            dest_str = strtok(NULL, str); // dont know why it doesnt take the second word

            // Variable Definition
            char cTemp;
            FILE *fpSourceFile = fopen(src_str, "rb");
            FILE *fpTargetFile = fopen(dest_str, "wb");

            // Code Section

            // Read From The Source File - "Copy"
            while (fread(&cTemp, 1, 1, fpSourceFile) == 1)
            {
                // Write To The Target File - "Paste"
                fwrite(&cTemp, 1, 1, fpTargetFile);
            }

            // Close The Files
            fclose(fpSourceFile);
            fclose(fpTargetFile);
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

void fork_echo(char *str)
{
    // str = ECHO dolev is gay

    memcpy(str, str + 5, MAX_LIMIT - 4);

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
        printf("dolev\n");
        char *args[] = {bin_path, str};
        execv(bin_path, args);
    }
}