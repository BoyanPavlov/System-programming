#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        int oldOut = dup(1); // запазваш стандартния вход за можеш да го върнеш после
        close(1);            // затваряш входа
        int fd = 0;
        dup(fd); // пренасочваш във файл

        if ((fd = open("error", O_CREAT | O_RDWR | O_TRUNC, 0744)) < 0)
        {
            printf("problem with file erros\n");
            exit(1);
        }
        write(fd, "Argc is less than 3", 19); // пишеш във файла
        close(1);                             // затваряш този файл(взели сме най-малкия свободен дескриптор)
        dup(oldOut);                          // отрваряш си пак стандартния вход
    }

    char command[10] = {};
    int bytesRead = read(0, command, 10);
    command[bytesRead - 1] = '\0';

    if (fork() == 0)
    {
        if ((execlp(command, command, 0)) == -1)
        {
            printf("Bad command\n");
            exit(1);
        }
    }
    else
    {
        if ((execlp("head", "head", "-n2", argv[2], 0) == -1)) // cannot enter here, don't know why
        {
            int fileOp = 0;
            if ((fileOp = open(argv[1], O_CREAT | O_RDWR | O_APPEND, 0744)) < 0)
            {
                printf("Couldn't open %s\n", argv[1]);
                exit(1);
            }
            write(fileOp, command, bytesRead);
            close(fileOp);
        }
    }

    close(1);
    return 0;
}
