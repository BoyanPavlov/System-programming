#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();

    // 8 proccesses, 3 prints == 24 prints

    printf("Parent1 pid: %d and Child1's pid: %d\n", getpid(pid1), getppid(pid1));
    printf("Parent2 pid: %d and Child2's pid: %d\n", getpid(pid2), getppid(pid2));
    printf("Parent3 pid: %d and Child3's pid: %d\n", getpid(pid2), getppid(pid2));
    return 0;
}
