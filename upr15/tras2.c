#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    int fd, k, status;
    fd = open(argv[1], O_RDWR);
    if (fork())
    {
        wait(&status);
        dup(fd);
        write(1, "who\n", 4);
        execlp("who", "who", "- u", 0);
        write(fd, " exam1\n", 5); // no - because of the exec even though it's invalid one
    }
    else
    {
        close(1);
        dup(fd);
        for (k = 0; k <= 3; k++)
            write(1, "exam2\n", 6);
    }
    execlp("pwd", "pwd", 0);

    exit(0);
}

// execute child
// execute main
// goes to the parent
// try to execute the exec and blocks there