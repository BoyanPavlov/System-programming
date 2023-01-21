#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t pid1 = fork();
    pid_t pid2 = fork();

    // 4 proccesses, 2 prints == 8 prints

    printf("Parent1 pid: %d and Child1's pid: %d\n", getpid(pid1), getppid(pid1));
    printf("Parent2 pid: %d and Child2's pid: %d\n", getpid(pid2), getppid(pid2));
    return 0;
}
