#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>

#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Needed 2 file names\n ");
        exit(1);
    }

    pid_t pid1 = fork();
    int fd1;

    if (((fd1 = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0774)) < 0))
    {
        printf("Problem creating the file %s\n", argv[1]);
        exit(1);
    }

    if (pid1 > 0)
    {
        write(fd1, "hello1\n", 7);
    }
    else if (pid1 == 0)
    {
        write(fd1, "hello2\n", 7);
    }
    else
    {
        printf("Couldn't fork\n");
        exit(1);
    }

    close(fd1);
    exit(0);
}
