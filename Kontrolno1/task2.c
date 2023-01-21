#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// out fileName comand _ _ ..

int main(int argc, char const *argv[])
{
    int status = 0;
    pid_t pid = fork();
    if (pid > 0)
    {
        wait(&status); // getting the exit status of the command below, but you don;t assign it to anything
                       // the number is the return from the wait !!!
        printf("\n%d", status);
        int stat;
        if (status == 0) // if it's valid enter here
        {
            if (fork())
            {
                wait(&stat);
                if (stat == 0)
                {
                    printf("\n%d", getpid());                      // print the number of the process WRONG look at row 14
                    printf("\nThe command exit with: %d\n", stat); // print the exit of the comand RIGHT
                }
            }
            else
            {
                if ((execvp(argv[2], &argv[2])) == -1)
                {
                    printf("\ncannot execute\n");
                    exit(1);
                }
            }
        }
    }
    else if (pid == 0)
    {
        if ((execlp("tail", "tail", argv[1], 0)) == -1)
        {
            printf("cannot execute tail");
            exit(1);
        }
    }
    else
    {
        printf("Coulnd't fork\n");
        exit(1);
    }
    execlp("ls", "ls", NULL);
    exit(0);
}
