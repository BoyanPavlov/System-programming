#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

    int fds[2];
    pipe(fds);
    pid_t pid = fork();

    if (pid > 0)
    {
        // parent
        close(1);
        dup(fds[1]);
        close(fds[0]);
        close(fds[1]);
        execlp(argv[1], argv[1], NULL);
    }
    else if (pid == 0)
    {
        // child
        close(0);
        dup(fds[0]);
        close(fds[1]);
        close(fds[0]);
        execlp(argv[2], argv[2], NULL);
    }
    else
    {
        // error
        printf("Couldn't fork\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
