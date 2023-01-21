#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        char buffer[200] = {};

        read(0, buffer, 200);
        write(1, buffer, 200);
    }

    exit(0);
}