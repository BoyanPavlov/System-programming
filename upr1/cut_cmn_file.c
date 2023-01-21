#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int f1 = 0;
    char buf[512] = {};
    int read_ = 0;

    if (argc != 2)
    {
        printf("expected 2 arguments\n");
        exit(1);
    }

    if ((f1 = open(argv[1], O_RDONLY)) == -1)
    {
        printf("problem in opening\n");
        exit(1);
    }

    printf("Please enter m and n: cut -c m - n %s", argv[1]);
    int m, n = 0;
    scanf("%d %d", &m, &n);
    int counter = 0;
    if (m >= n)
    {
        printf("error m >= n");
        exit(1);
    }

    while ((read_ = read(f1, buf, sizeof(buf) / sizeof(buf[0]))) > 0)
    {
        counter += read_;
        if (counter > n)
        {
            for (int i = m; i < n; i++)
            {
                printf("%c", buf[i]);
            }
        }
    }
    close(f1);
    exit(0);
}
