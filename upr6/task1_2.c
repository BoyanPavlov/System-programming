#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        write(2, "Invalid number of given arg\n", 29);
        exit(1);
    }

    int fd = 0;
    if ((fd = open(argv[2], O_RDONLY)) == -1)
    {
        printf("File couldn't open\n");
        exit(1);
    }

    pid_t pid = fork();
    if (pid > 0)
    {
        int status;
        wait(&status);

        if (!WIFEXITED(status))
        {
            write(1, "Successful exectution of exec\n", 31);
        }
        
        // second version
        // if (status == 0)
        // {
        //     write(1, "Successful exectution of exec\n", 31);
        // }
    }
    else if (pid == 0)
    { // ./a.out str file
        if ((execlp("grep", "grep", argv[1], argv[2], NULL)) < 0)
        {
            printf("problem\n");
            exit(1);
        }
    }
    else
    {
        write(2, "Couldn't fork\n", 15);
        exit(1);
    }
    close(fd);

    exit(0);
}
