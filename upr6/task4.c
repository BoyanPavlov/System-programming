#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();

    if (pid > 0)
    {

        int stat;
        wait(&stat);
        printf("%d\n", stat);
        if (WIFEXITED(stat))
        {
            printf("command was\"");

            for (int i = 1; i < argc; i++)
            {
            printf(" %s", argv[i]);
            }

            printf("\"\n");
        }
    }
    else if (pid == 0)
    {
        if ((execvp(argv[1], (argv + 1))) < 0)
        {
            printf("problem\n");
            exit(1);
        }
    }
    else
    {
        write(2, "Couldn't fork\n", 15);
        exit(1);
    }

    exit(0);
}
