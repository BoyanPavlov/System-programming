#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int f[15];
    char buf[50] = {};

    if (argc < 2)
    {
        printf("you haven't entered files\n");
        exit(1);
    }
    for (size_t i = 1; i < argc; i++)
    {
        if ((f[i] = open(argv[i], O_CREAT | O_EXCL | O_TRUNC | O_WRONLY, 0644)) == -1)
        {
            printf("Problem in opening\n");
            exit(1);
        }
    }
    // scanf("%s", buf);
    read(0, buf, 50);
    for (size_t i = 1; i < argc; i++)
    {
        write(f[i], buf, 50);
        close(f[i]);
    }

    exit(0);
}