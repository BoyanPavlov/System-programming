#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int f1 = 0;
  int n = 0;
  char buf[512] = {};

  if (argc < 2)
  {
    printf("Needed at least 2 arguments\n");
    exit(1);
  }

  if ((f1 = open(argv[argc - 1], O_RDONLY)) == -1)
  {
    printf("Can't open file\n");
    exit(1);
  }

  int lenght = strlen(argv[1]);

  int charFlag = 0;
  int wordFlag = 0;
  int rowFlag = 0;

  for (int i = 0; i < lenght; i++)
  {
    if (argv[i] == 'c')
    {
      charFlag = 1;
    }
    if (argv[i] == 'w')
    {
      wordFlag = 1;
    }
    if (argv[i] == 'l')
    {
      rowFlag = 1;
    }
  }

  int counter = 0;
  int rows = 0;
  int words = 0;

  while ((n = read(f1, buf, 512)) > 0)
  {
    for (int i = 0; i < 512; i++)
    {
      if (buf[i] == ' ')
      {
        words++;
      }
      else if (buf[i] == '\n')
      {
        rows++;
      }
    }
    counter = counter + n;
  }

  if (charFlag)
  {
    printf("%d ", counter);
  }
  if (wordFlag)
  {
    printf("%d ", words);
  }
  if (rowFlag)
  {
    printf("%d ", rows);
  }

  if (charFlag == wordFlag && wordFlag == rowFlag && rowFlag == 0)
  {
    printf("%d %d %d \n", counter, words, rows);
  }

  printf("\n");

  exit(0);
}
