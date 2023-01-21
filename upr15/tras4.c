#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int a = 2000;

    if (fork())
    {
        a /= 2;
        printf("Stoinostta na a = %d parent1\n", a);
    }
    else
    {
        if (fork())
        {
            a *= 2;
            printf("Stoinostta na a = %d parent2\n", a);
            if (execlp("ps", "ps", "- u", "student", 0) == -1)
            {
                a = a + 2;
                printf("Stoinostta na a = %d parent2_exec\n", a);
            }
        }
        else
        {
            a += 2;
            printf("Stoinostta na a = %d child2\n", a);
        }
    }
    a++;
    printf("Stoinostta na a = %d main\n", a);

    exit(0);
}

// Expected Output:
// Stoinostta na a = 1000
// Stoinostta na a = 1001
// Stoinostta na a = 4000
// Stoinostta na a = 4002 //should remove this one
// Stoinostta na a = 2002
// Stoinostta na a = 2003

//  Actual output:
//  Stoinostta na a = 1000 parent1
//  Stoinostta na a = 1001 main
//  Stoinostta na a = 4000 parent2
//  Stoinostta na a = 2002 child2
//  Stoinostta na a = 2003 main
//  error: garbage option