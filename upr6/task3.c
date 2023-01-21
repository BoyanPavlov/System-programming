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
        if (WIFEXITED(stat))
        {
            printf("command was\"");

            printf(" %s", argv[1]);
            printf("\"\n");
        }
    }
    else if (pid == 0)
    {
        if ((execlp(argv[1], argv[1], NULL)) < 0)
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
