#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd, fd1, k, status;
    if ((fd = open(argv[1], O_RDWR)) == -1)
    {
        printf("\n Cannot open\n");
        exit(1);
    }
    if ((fd1 = open(argv[2], O_RDWR)) == -1)
    {
        printf("\n Cannot open\n");
        exit(1);
    }

    if (fork())
    {
        wait(&status);
        dup(fd);
        write(1, "test1\n", 6);
        execlp("who", "who", 0);
        write(fd, "test2\n", 6); // doesn't execute
    }
    else
    {
        close(1);
        dup(fd); // тук пренасочваш всичко към файла от стандартния вход
        if (fork())
        {
            write(1, "test3\n", 6);
            write(fd1, "test4\n", 6);
        }
        else
        {
            for (k = 0; k <= 2; k++)
            {
                write(1, "test5\n", 6);
            }
            write(fd1, "test6\n", 6);
        }
        execlp("ps", "ps", "aux", 0);
        write(1, "test7\n", 6);  // ignore
        write(fd, "test8\n", 6); // ignore
    }

    return 0;
}

// Output:
// test1
// who

// File1:
// test3
// test5
// test5
// test5
// ps aux

// File2:
// test4
// test6