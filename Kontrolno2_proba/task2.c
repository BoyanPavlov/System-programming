// #include <stdlib.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// // ./program.out file1 file2
// int main(int argc, char const *argv[])
// {
//     int status;
//     int fd1;
//     int fd2;
//     if (fork())
//     {
//         wait(&status);
//         printf("Code: %d", status);
//     }
//     else
//     {
//         close(0);
//         close(1);
//         close(2);
//         if ((fd1 = open(argv[1], O_CREAT | O_RDWR, 0744)) == -1)
//         {
//             printf("Couldn't open file\n");
//             exit(1);
//         }
//         if ((fd2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0744)) == -1)
//         {
//             printf("Couldn't open file\n");
//             exit(1);
//         }
//         dup(fd1);
//         dup(fd2);
//         execlp("grep", "grep", "pts", 0);
//     }

//     exit(0);
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd1, fd2, status;
    if (fork())
    {
        wait(&status);
        printf("%d\n", status);
    }
    else
    {
        if ((fd1 = open(argv[1], O_RDONLY)) == -1)
        {
            printf("Can't open first file\n");
            exit(-1);
        }

        if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
        {
            printf("Can't open second file\n");
            exit(-1);
        }
        dup2(fd1, 0);
        dup2(fd2, 1);
        dup2(fd2, 2);

        close(fd1);
        close(fd2); // we are closing them but the exec inherits them and uses them
        // we are closing them because it's a good practise
        // and we won;t be using them
        execlp("grep", "grep", "pts", 0);
    }
    exit(0);
}