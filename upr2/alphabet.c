#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char buf[15];

int main(int argc, const char *argv[])
{
    int fd = 0;
    if (argc > 2)
    {
        printf("invalid number of arguments\n");
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("File couldn't open\n");
        exit(1);
    }

    pid_t pid = fork();
    if (pid > 0)
    {
        int status = 0;
        wait(&status);

        // you can rewrite it as status == 0
        // if you want to get the number of the process ->
        // print num, where num= wait(&status);
        // if you want to print the status of a command ->
        // print status
        if (WIFEXITED(status))
        {
            int readCharacters = 0;
            int i = 0;
            int curr = 0;
            for (i = 5; i >= 1; i--)
            {
                if ((readCharacters = read(fd, buf, 15) && (curr = lseek(fd, 15, SEEK_CUR))) > 0)
                {
                    write(1, buf, 15);
                    write(1, "\n", 1);
                    // printf("%s \n", buf);
                }
            }
        }
    }
    else if (pid == 0)
    {
        if ((execlp("wc", "wc", "-c", argv[1], NULL)) < 0)
        {
            printf("problem");
            exit(1);
        }
    }
    else
    {
        perror("Couldn't fork");
    }

    exit(0);
}