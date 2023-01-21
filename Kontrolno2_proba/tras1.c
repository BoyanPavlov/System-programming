#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fdi, fdio, nb1, nb2;
    char buff[15];
    fdi = open("abc", O_RDONLY);
    fdio = open("abc", O_RDWR);

    nb1 = read(fdi, buff, 6);
    write(1, buff, nb1);

    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buff, 6);
    write(1, buff, nb1);

    lseek(fdio, -18, SEEK_END);
    write(fdio, "tra", 3);

    write(fdio, "vel", 3);
    nb2 = read(fdio, buff, 5); 
    write(1, buff, nb2);
    write(1, "time", 4);

    lseek(fdi, -2, SEEK_END);
    nb2 = read(fdi, buff, 2);
    write(1, buff, nb2);

    exit(0);
}
// Output:
// Let's changee thetimed!

// file: Let's gotravele the world!