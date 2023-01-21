#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        printf("expected file name as argument\n");
        exit(1);
    }

    int fd = 0;

    if ((fd = open(argv[1], O_CREAT | O_RDWR, 0744)) == -1)
    {
        printf("Couldn't open the file\n");
        exit(1);
    }

    while (1)
    {
        char buf[50] = {};
        read(0, buf, 50);
        write(fd, buf, 50);
    }

    exit(0);
}