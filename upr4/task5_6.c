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

    int fd = 0;
    if ((fd = open(argv[1], O_CREAT | O_WRONLY, 0744)) == -1)
    {
        printf("Problem with creating or opening file\n");
        exit(1);
    }

    char temp[1];
    char temp2[5];

    for (int i = 0; i < 10; i++)
    {
        // write doesn't work - it separates the streams of output
        printf("EXAMPLE ");

        temp[0] = i + 48;
        write(fd, temp, 1);

        sprintf(temp2, "i=%d\n", i);
        write(fd, temp2, strlen(temp2));
        printf(" HELLO\n");
    }

    close(fd);
    exit(0);
}
