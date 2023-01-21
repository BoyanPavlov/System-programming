#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
main(int argc, char *argv[])
{
    int fd, j, nb1, status;
    char buf[5];
    if (fork())
    {
        printf("we are in parent at first\n");

        wait(&status);
        printf("we are in parent\n");
        execlp("cat", "cat", argv[1], 0);
    }
    else
    {
        printf("we are in child\n");

        j = dup(1); // saves the standart output descriptor
        fd = open(argv[1], O_RDWR);
        nb1 = read(0, buf, 7);
        write(j, buf, nb1);
        nb1 = read(fd, buf, 5);           // error or something, I mean empty file or hello
        printf("line === passed ");       // \n different unexpected resuls ...
        write(1, buf, nb1);               // empty string
        write(fd, "\n", 1);               // new line in the file
        write(fd, buf, nb1);              // nothing done here
        write(j, buf, 3);                 // this line here changes the whole input and adds hel after helloWo
        printf(" are those executed?\n"); // scratch the upper one - now we have a new line and el concatenated to line === passed  are those executed?
        close(fd);
        close(j);
        exit(0);
    }
}

// wtfff

// nope
//  we are in parent at first
//  we are in child
//  helloWorld
//  helloWoline === passedhellohel
//  are those executed?
//  we are in parent

// file:
//
// empty or hello

//
// we are in parent at first
// we are in child
// helloWorld
// helloWo

// elline === passed  are those executed?
// we are in parent