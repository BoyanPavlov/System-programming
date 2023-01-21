#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = 0;
    int fd1 = 0;
    int fd2 = 0;
    int fd3 = 0;

    char myFile[] = "fff";

    if ((fd = open(myFile, O_CREAT | O_RDWR, 0777)) == -1)
    {
        printf("Problem creating the file %s ", myFile);
    }

    fd1 = open(myFile, O_RDONLY);
    fd2 = open(myFile, O_WRONLY);
    fd3 = open(myFile, O_RDWR);

    char buffer[6] = {};
    char buffer1[5] = {};
    char buf[10] = {};

    write(fd2, "Hello world", 12);
    read(fd3, buffer, 6);
    write(1, buffer, 6);

    read(fd1, buffer1, 5);
    write(1, buffer1, 5);

    write(fd3, "chill", 5);
    // cannot read after writing in the file
    read(fd3, buf, 5);
    write(1, buf, 5);

    read(fd1, buf, 5);
    write(1, buf, 5);

    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);
    exit(0);
}
