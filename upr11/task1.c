#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

    int fds[2];
    pipe(fds);
    pid_t pid = fork();

    if (pid > 0)
    {
        // parent
        close(1);    // closing the standart output
        dup(fds[1]); // creating a new descriptor in order to be able to work with it

        close(fds[0]); // closing the ones for reading and writing
        close(fds[1]); // in order to work with only 2 d, not with 4
        execlp("who", "who", NULL);
    }
    else if (pid == 0)
    {
        // child
        close(0);
        dup(fds[0]);

        close(fds[1]);
        close(fds[0]);
        execlp("wc", "wc", "-l", NULL);
    }
    else
    {
        // error
        printf("Couldn't fork\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

// LYUBEN

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>

// int main(int argc, char **argv)
// {
//     int fd[2];
//     pipe(fd);

//     if (fork())
//     {
//         // wait(NULL);
//         close(1);
//         dup(fd[1]);
//         close(fd[1]);
//         close(fd[0]);
//         execlp("who", "who", NULL);
//     }
//     else
//     {
//         close(0);
//         dup(fd[0]);
//         close(fd[1]);
//         close(fd[0]);
//         execlp("wc", "wc", "-l", NULL);
//         exit(EXIT_FAILURE);
//     }

//     exit(EXIT_SUCCESS);
// }

// ANGEL
//  #include <stdio.h>

// int main(int argc, char **argv)
// {
//     int fd[2];
//     pipe(fd);
//     int pid = fork();
//     if (pid == -1)
//     {
//         printf("Error\n");
//         exit(1);
//     }
//     else if (pid > 0)
//     {
//         close(1);
//         dup(fd[1]);
//         close(fd[1]);
//         close(fd[0]);
//         execlp("who", "who", 0);
//     }
//     else
//     {
//         close(0);
//         dup(fd[0]);
//         close(fd[0]);
//         close(fd[1]);
//         execlp("wc", "wc", "-l", 0);
//     }
//     return 0;
// }
