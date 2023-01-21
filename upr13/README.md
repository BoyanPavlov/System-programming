Упражнение 13 - трасировка

Задача 1. Напишете какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С
 
           ………
int  pid,  var = 1, status;

if  (( pid = fork()) = = 0 )  {var+=2; 
printf (“\n Var = %d “, var);} 
else { wait(&status);  var++ ;
 printf (“\n Var = %d “, var); 
 exit(0);}
--var;
printf (“\n Var = %d “, var);


Задача 2 Какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на Си 
         ………
#define  COM  “ps”
main()
{
int  i=2, status;
if ( fork() ) {wait(&status); --i;
                    printf( “ Stoinostta na i = %d;”, i);}
else  { i++; 
         if ( execlp ( COM,  COM, 0) == -1) { i=i+2;
                     printf( “ Stoinostta na i = %d;”, i);}
          }
printf( “ Stoinostta na i = %d;”, --i);
}







Задача 3 Ако в резултат на успешна компилация на зададения по-долу код на С е създаден изпълним файл с име progA и в текущата директория има текстов файл fileA.txt със съдържание

     abc123-x
     999aaa
     yyyyyy6xxxxx

напишете вдясно какво и къде ще се изведе,  в случай на успешното изпълнение   на progA  след стартиране с командния ред
./progA  fileA.txt  file1

#include	<stdio.h>
main(argc, argv )
int argc; char *argv[] ;
{
	int fd, fd1, i = 0 ;
	char c;
	if  (  (  fd = open ( argv[1], O_RDONLY)  )  == -1 )
	{  printf (“\n Cannot open %s  ”, argv[1] );	exit(1);  	}
if  (( fd1 = open ( argv[2], O_CREAT|O_TRUNC|O_RDWR, 0644)  )== -1 )
	{  printf (“\n Cannot open %s  ”, argv[2] );	exit(1);  	}

	while  (   read ( fd, &c, 1 )    )
	{	++i;
		if  (  c == '\n' )   
                        {    if ( i < 10 )  
                                 for ( i ; i < 15 ; i++ )
                                    {write(1,”$”,1); write(fd1,”#”,1);}
                              i=0;
                          }
                         write(1,&c,1);     			
	}
	close(fd); close(fd1);	


