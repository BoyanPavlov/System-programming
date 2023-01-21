#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fdR = 0;
    int fdW = 0;
    if (argc > 2)
    {
        printf("invalid number of arguments\n");
        exit(1);
    }

    if ((fdR = open(argv[1], O_RDONLY)) == -1)
    {
        printf("File couldn't open\n");
        exit(1);
    }

    if ((fdW = open(argv[1], O_WRONLY)) == -1)
    {
        printf("File couldn't open\n");
        exit(1);
    }

    lseek(fdW, -2, SEEK_END);
    write(fdW, "wxyz", 5);

    lseek(fdW, 5, SEEK_SET);
    write(fdW, "12", 5);

    char buf[20] = {};
    read(fdR, buf, 20);
    write(1, buf, 20);

    close(fdW);
    close(fdR);

    exit(0);
}
