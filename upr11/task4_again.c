#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fds[2];
    pipe(fds);

    if (fork() > 0)
    {
        close(1);
        dup(fds[1]);

        close(fds[1]);
        close(fds[0]);

        execlp(argv[1], argv[1], 0);
    }
    else
    {
        int fds_1[2];
        pipe(fds_1);

        close(fds[1]);
        close(0);
        dup(fds[0]);
        close(fds[0]);

        if (fork() > 0)
        {
            close(1);
            dup(fds_1[1]);
            close(fds_1[0]);
            close(fds_1[1]);
            execlp(argv[2], argv[2], argv[3], 0);
        }
        else
        {

            // close(0);// wtf - if you uncoment this line the program doesn't work
            dup(fds_1[0]);
            close(fds_1[0]);
            close(fds_1[1]);
            execvp(argv[4], &argv[4]);
        }
    }
    return 0;
}
