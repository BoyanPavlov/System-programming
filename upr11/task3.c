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
        close(1);      // затваряш стандартния изход
        dup(fds[1]);   // правиш си нов дескриптор за да можеш да работиш с нещо
        close(fds[0]); // затваряш тези за четене и писане, за да може
        close(fds[1]); // да работиш само с 2 дескриптора, а не със 4
        execlp(argv[1], argv[1], NULL);
    }
    else if (pid == 0)
    {
        // child
        close(0);
        dup(fds[0]);
        close(fds[1]);
        close(fds[0]);
        execvp(argv[2], &argv[2]);
    }
    else
    {
        // error
        printf("Couldn't fork\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
