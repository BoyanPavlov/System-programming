#include <stdio.h>
#include <fcntl.h>

#define CMD "cal"

int main()
{
    int m = 3;
    int n = 0;
    int status, fd;
    char buf[12];

    if ((fd = open("f1", O_RDWR)) == -1)
    {
        printf("\n Cannot open file\n");
        exit(1);
    }
    if (fork() > 0)
    {
        wait(&status);
        --m;
        n--;
        read(fd, buf, 4);
        write(1, buf, 4);
        printf("\n m= %d n= %d\n", m, n);
    }
    else
    {
        for (n = 1; n <= 3; n++)
        {
            read(fd, buf, 4);
            write(1, buf, 4);
            m = n + m;
            printf("\n m= %d n= %d\n", m, n);

            if ((execlp(CMD, CMD, 0)) == -1) // after this one - nothing else execute below
            {                                // Once the execlp() function is called, control is transferred to the new program
                                             // and the execution of the current program is halted.
                write(1, buf, 4);
            }
            printf("\n m= %d n= %d\n", m, n);
            exit(2);
        }
    }
    write(fd, buf, 4);
    if ((execlp("wc", "wc", "-c", "f1", 0)) == -1)
    {
        printf("\n m= %d n= %d\n", m, n);
    }
    else
    {
        write(1, buf, 4);
    }

    return 0;
}
// 1234
//  m= 4 n= 1
// calendar

// 5678
//  m= 2 n= -1
// 12 f1