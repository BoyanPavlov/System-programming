#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// works for numbers 1-9
int main(int argc, char const *argv[])
{
    int fdR = 0;
    if (argc > 3)
    {
        printf("invalid number of arguments\n");
        exit(1);
    }

    if ((fdR = open(argv[2], O_RDONLY)) == -1)
    {
        printf("File couldn't open\n");
        exit(1);
    }

    int number = argv[1][0] - '0';
    lseek(fdR, number, SEEK_CUR);

    char buf[20] = {};

    read(fdR, buf, 20);
    write(1, buf, 20);

    close(fdR);

    exit(0);
}
