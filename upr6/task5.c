#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if ((execlp(argv[i], argv[i], NULL)) < 0)
        {
            printf("problem\n");
            exit(1);
        }
        printf("%d \n", getpid());
    }

    exit(0);
}
