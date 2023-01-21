#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
main(int argc, char *argv[])
{
    int fd, i, status;
    if (fork())
    {
        wait(&status);
        for (i = 0; i <= 3; i++)
        {
            write(1, "cal\n", 4);
            execlp("cal", "cal", 0); // execute once then and this ends the loop
            write(1, "hello1\n", 6); // this line wasn't reached
        }
    }
    else
    {
        close(1);
        fd = open(argv[1], O_RDWR);
        write(1, "hello2\n", 6); // we take the smalles fd - 1 and use it
    }                            // so everything goes to the file
    write(1, "hello3\n", 6);     // no exec to stop the child so we are here
}
