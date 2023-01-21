#include <stdio.h>

int main(int argc, char **argv)
{
    int fd[2];
    pipe(fd);

    if (fork() > 0)
    {
        close(1);
        dup(fd[1]);

        close(fd[1]);
        close(fd[0]);
        execlp(argv[1], argv[1], 0);
    }
    else
    {
        int fd2[2];
        pipe(fd2);
        close(fd[1]);
        if (fork() > 0)
        {
            close(0);
            dup(fd[0]);
            close(fd[0]);

            close(1);
            dup(fd2[1]);
            close(fd2[0]);
            close(fd2[1]);
            execlp(argv[2], argv[2], NULL);
            // execlp(argv[2], argv[2], argv[3],0);//work better, but sometimes it doesn't...
        }
        else
        {
            close(0);
            dup(fd[0]);
            close(fd[0]);

            dup(fd2[0]);
            close(fd2[0]);
            close(fd2[1]);
            execvp(argv[4], &argv[4]);
        }
    }
}
