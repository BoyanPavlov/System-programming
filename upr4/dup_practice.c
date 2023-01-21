#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    if (argc > 2)
    {
        write(1, "Problem with arguments count\n", 29);
        exit(1);
    }

    int fd = 0;

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("File couldn't open\n");
        exit(1);
    }

    int fd2 = dup(fd); // dup returns -1 if there is an error
    if (fd2 == -1)
    {
        write(1, "Problem with dup \n", 19);
        close(fd);
        exit(1);
    }

    char buffer[10];
    int read_ = 0;
    int count = 0;

    while ((read_ = read(fd2, buffer, 10)) > 0 && count < 2)
    {
        write(1, buffer, 10);
        count++;
    }

    write(1, buffer, 10);

    while ((read_ = read(fd, buffer, 10)) > 0)
    {
        write(1, buffer, 10);
    }
    close(fd2);

    exit(0);
}
