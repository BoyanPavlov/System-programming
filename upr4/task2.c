#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{

    for (int i = 0; i < 10; i++)
    {
        write(1, "EXAMPLE\n", 9);
    }

    exit(0);
}
