#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Expected 1 argument\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        write(1, "EXAMPLE\n", 9);
    }

    int fd = 0;
    if ((fd = open(argv[1], O_CREAT | O_RDWR, 0744)) == -1)
    {
        printf("Problem with creating or opening file\n");
        exit(1);
    }
    int fd2 = dup(fd);

    for (size_t i = 0; i < 10; i++)
    {
        write(fd2, "EXAMPLE\n", 9);
    }

    close(fd2);
    exit(0);
}
