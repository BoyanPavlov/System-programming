#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// ./program.out com1 com2 _ _
// int main(int argc, char const *argv[])
// {
//     int fds[2];
//     pipe(fds);
//     int status;

//     if (fork())
//     {
//         close(1);
//         dup(fds[1]);
//
//         close(fds[1]);
//         close(fds[0]);
//         execlp(argv[1], argv[1], 0);
//     }
//     else
//     {
//         close(0);
//         dup(fds[0]);
//
//         close(fds[0]);
//         close(fds[1]);
//         execvp(argv[2], &argv[2]);
//     }
//
//     // doesn't get here ofc
//     wait(&status);
//     printf("Pid: %d", getpid());
//
//     return 0;
// }
// okay in this task for two commands at the same time U don't use pipe, that's how you do it

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int num1, num2, status1, status2;

    if (fork())
    {
        num1 = wait(&status1);
        if (fork())
        {
            num2 = wait(&status2); // That's how you get the number of a procces
            printf("status1= %d num1= %d\n", status1, num1);
            printf("status2= %d num2= %d\n", status2, num2);
        }
        else
        {
            execvp(argv[2], &argv[2]);
        }
    }
    else
    {
        execlp(argv[1], argv[1], 0);
    }

    exit(0);
}