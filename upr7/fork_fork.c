#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t pid1 = fork();

    if (pid1 > 0)
    {
        // parent
        printf("Parent1 pid: %d and Child1's pid: %d\n", getpid(pid1), getppid(pid1));
    }
    else if (pid1 == 0)
    {
        // child
        pid_t pid2 = fork();
        printf("Parent2 pid: %d and Child2's pid: %d\n", getpid(pid2), getppid(pid2));
    }
    else
    {
        perror("Couldn't fork\n");
        exit(1);
    }

    exit(0);
}
