#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define COM "ps"

int main()
{
    int i = 2, status;

    if (fork())
    {
        wait(&status);
        --i;
        printf("Stoinostta na i = % d; parent\n", i);
    }
    else
    {
        i++;
        if (execlp(COM, COM, 0) == -1)
        {
            i = i + 2;
            printf("Stoinostta na i = % d;\n", i);
        }
        // doesn't execute main because exec
    }
    printf("Stoinostta na i = % d; main\n", --i);
}

// ps
// Stoinostta na i = 1
// Stoinostta na i = 0 //continues from parent