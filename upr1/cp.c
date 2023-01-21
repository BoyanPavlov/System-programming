#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{

    char buffer[512] = {};
    int f1 = 0;
    int f2 = 0;
    int read_ = 0;

    if (argc != 3)
    {
        printf("expected 3 arg, - 2 files\n");
        exit(1);
    }

    if ((f1 = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Can't open file\n");
        exit(1);
    }

    if ((f2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    {
        printf("\ncopy: can't create %s\n", argv[2]);
        exit(1);
    }

    while ((read_ = read(f1, buffer, 512)) > 0)
    {
        if (read_ != write(f2, buffer, read_))
        {
            printf("Problem in writing in the file\n");
        }
    }

    close(f1);
    close(f2);

    exit(0);
}