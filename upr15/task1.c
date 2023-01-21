#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// program command fileName
int main(int argc, char const *argv[])
{
    int status1, status2;

    char command[15] = {};
    write(1, "Enter command: ", 15);

    int readBytes = read(1, command, 15);
    command[readBytes - 1] = '\0';

    int fds[2];
    int fdO;
    pipe(fds);

    if (fork())
    {
        wait(&status1);

        close(0);
        dup(fds[0]);

        close(fds[0]);
        close(fds[1]);

        if (fork())
        {
            wait(&status2);

            if ((fdO = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0744)) == -1)
            {
                printf("Couldn't open the file: %s", argv[2]);
                exit(1);
            }
            printf("Stat1: %d\n", status1);
            printf("Stat2: %d\n", status2);

            write(fdO, "Stat1: ", 7);
            write(fdO, &status1, sizeof(status1));
            write(fdO, "Stat2: ", 7);
            write(fdO, &status2, sizeof(status2));

            // nah
            //  char string1[15] = {};
            //  char string2[15] = {};
            //  sprintf(string1, "%d", status1);
            //  sprintf(string2, "%d", status2);

            // write(fdO, "Stat1: ", 7);
            // write(fdO, string1, sizeof(string1));
            // write(fdO, "Stat2: ", 7);
            // write(fdO, string1, sizeof(string2));

            close(fdO);
        }
        else
        {
            if ((execlp(command, command, 0)) == -1)
            {
                printf("Couldn't execute %s", argv[1]);
                exit(1);
            }
        }
    }
    else
    {

        close(1);
        dup(fds[1]);

        close(fds[1]);
        close(fds[0]);

        if ((execlp(argv[1], argv[1], 0)) == -1)
        {
            printf("Couldn't execute %s", argv[1]);
            exit(1);
        }
    }

    exit(0);
}
