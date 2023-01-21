#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    int j = 7;

    if (fork() == 0)
    {
        j++;
        exit(0);
        if (execlp("who", "who", 0) == -1)
            j = 7;
        else
            printf("\nStoinostta na j = % d ", j);
    }
    else
    {
        --j;
        printf("\nStoinostta na j = % d ", j);
    }

    exit(0);
}

// Output: Stoinostta na j = 6