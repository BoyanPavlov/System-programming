#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int pid, var = 1, status;

    if ((pid = fork()) == 0)
    {
        var += 2;
        printf("\n Var = % d kiddo", var);
    }
    else
    {
        wait(&status);
        var++;
        printf("\n Var = % d parent", var);
        exit(0); // you have exit here, without it - U you would exec the main too
    }

    printf("\n Var = % d main", var); // after the child procces exec this one : var=3
    --var;
    printf("\n Var = % d main", var); // var=2, then execute the parent pr

    exit(0);
}
// Var = 3 kiddo
// Var = 3 main
// Var = 2 main
// Var = 2 parent