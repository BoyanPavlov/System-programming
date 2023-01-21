#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char buffer[50] = {};
    int i = 0;
    while (1)
    {
        write(1, "CI> ", 4);
        while ((read(0, &buffer[i], 1)) && buffer[i] != '\n')
        {
            if (buffer[i] == ' ')
            {
                continue;
            }
            else
            {
                i++;
            }
        }

        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
        }

        if (!strcmp(buffer, "quit") || !strcmp(buffer, "bye") || !strcmp(buffer, "logout"))
        {
            exit(0);
        }
        else
        {

            pid_t pid = fork();
            if (pid > 0)
            {
                wait();
                i = 0;
            }
            else if (pid == 0)
            {
                if (execlp(buffer, buffer, 0) < 0)
                {
                    printf("Cannot execute %s \n", buffer);
                    exit(1);
                }
            }
            else
            {
                printf("we are fucked\n");
                exit(1);
            }
        }
    }

    exit(0);
}
