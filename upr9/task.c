#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO - FIX it's not working at all
int main(int argc, char const *argv[])
{

    char buffer[50] = {};
    char cmd[10][50];
    int commandIndex = 0;
    int i = 0;
    int j = 0;
    while (1)
    {
        write(1, "CI> ", 4);
        while ((read(0, &buffer[i], 1)) && buffer[i] != '\n')
        {
            if (buffer[i] == ' ')
            {
                cmd[commandIndex][j] = '\0';
                commandIndex++;
                j = 0;
            }
            else
            {
                cmd[commandIndex][j] = buffer[i];
                j++;
                i++;
            }
        }
        // cmd[commandIndex] = NULL;

        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
        }
        printf("im here");

        // printf("%s  ", cmd[0]);
        // printf("%s  ", cmd[1]);
        // printf("%s  ", cmd[2]);

        for (int k = 0; k < commandIndex; k++)
        {
            printf("%s  ", cmd[k]);
            printf("%s \n", buffer);
        }

        if (!strcmp(buffer, "quit") || !strcmp(buffer, "bb") || !strcmp(buffer, "logout"))
        {
            exit(0);
        }
        // else
        // {
        //     pid_t pid = fork();
        //     if (pid > 0)
        //     {
        //         wait();
        //         i = 0;
        //     }
        //     else if (pid == 0)
        //     {
        //         if (execvp(cmd, cmd, NULL) < 0)
        //         {
        //             printf("Cannot execute\n");
        //             exit(1);
        //         }
        //     }
        //     else
        //     {
        //         printf("we are fucked\n");
        //         exit(1);
        //     }
        // }
    }

    exit(0);
}

// #include <stdio.h>
// #define YES 1
// #define NO 0
// #define MAXLINE 80
// #define MAXARG 10

// char *cmd[MAXARG], com[MAXLINE];
// int BG;

// main()
// {
//     int status, k, pid;

//     write(1, "COM>", 4);
//     while ((k = input_l()) >= 0)
//     {
//         if (k)
//         {
//             if ((pid = fork()) < 0)
//             {
//                 write(2, "Cannot fork\n", 12);
//                 exit(0);
//             }
//             else
//             {
//                 if (pid != 0)
//                     wait(&status);
//                 else
//                 {
//                     execlp(cmd[0], cmd[0], 0);
//                     write(1, "cannot exec ", 12);
//                     write(1, cmd[0], 10);
//                     exit(1);
//                 }
//             }
//         }
//         write(1, "\nCOM>", 5);
//     } /*  while  */
// }

// int input_l()
// {
//     int i, j, nbyt, word;

//     word = NO;
//     j = 0;
//     i = 0;
//     while ((nbyt = read(0, &com[j], 1)) != 0)
//     {
//         if (com[j] == ' ')
//         {
//             if (word == YES)
//             {
//                 word = NO;
//                 com[j++] = '\0';
//             }
//         }
//         else if (com[j] != '\n')
//         {
//             if (word == NO)
//             {
//                 word = YES;
//                 cmd[i++] = &com[j];
//             }
//             ++j;
//         }
//         else if (com[j] == '\n')
//         {
//             if (word == YES)
//                 com[j] = '\0';
//             cmd[i] = NULL;
//             if (strcmp(cmd[0], "logout") == 0)
//                 return (-1);
//             else
//                 return (i);
//         } /*  if  '\n'  */
//     }     /*  while  != EOF  */
//     if (nbyt == 0)
//         return (-1);
// }
