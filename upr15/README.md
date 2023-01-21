Упражнение 15


Задача 1. Напишете програма на C, която получава при стартиране два параметърa –команда без опции и аргументи и файл. Прочита от стандартния вход команда също без опции и аргументи. Ползвайки системните примитиви за работа с файлове и процеси в Linux, изпълнява канал между прочетената от стандартния вход команда и подадената като първи параметър такава. Накрая извежда кодът на завършване на канала на екрана и имената на двете команди в подадения като параметър файл.

Упражнение 15 - трасировка
Задача 1. Какво ще бъде изведено на стандартния изход при успешно изпълнение на дадения по-долу фрагмент от програма на Си (заградете верния отговор)
………
int  j  = 7 ;

if  ( fork() = = 0 )  {
      j++ ; exit(0);
      if  ( execlp (“who”,”who”,0 ) = = -1  )   j = 7;
      else   printf (“\nStoinostta na j = %d “, j); 
}
else  {  --j ;   printf (“\nStoinostta na j = %d “, j )  ;   }

а) Stoinostta na j = 8 ; 
    Stoinostta na j = 6; 
б) Stoinostta na j = 6;
в) Stoinostta na j = 7; 
г) изходът от изпълнението на командата who
д) нито един от посочените случаи

Задача 2 Като първи параметър на програма на С се подава съществуващ празен файл. Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С :
#include ……………..
main ( int argc, char *argv[] )
{      int fd, k, status;
       fd = open ( argv[1], O_RDWR) ;
           if ( fork() )
           { wait(&status);
              dup(fd);
               write ( 1, “who\n”, 4);
               execlp ( “who”, “who”,”-u”,0); 
              write (fd, “ exam1\n”,5);
             }
         else { close(1); dup(fd);
                 for ( k=0; k<=3; k++)
                 write (1, “exam2\n”,6); 
                 }
        execlp ( “pwd”, “pwd”,0);
 }

Задача 3 В текущия каталог се намира текстов файл fileD.txt със следното съдържание

	123456789
	$$abcdefg

Напишете вдясно какво ще бъде изведено на стандартния изход (терминала)и какво ще бъде съдържанието на новосъздадения фаил,  като резултат от изпълнението на файла, получен при успешна компилация на зададения по-долу програмен код на С, в който са използвани системни примитиви на ОС UNIX и LINUX:
#include	<stdio.h>
#include     <fcntl.h>
main( )
{       int fdr, fdw, n_byt, i = 0 , status;
	char symbols [ 40 ], c ;	
	if ( fork( ) )
	           {  wait ( &status);
	                if ( open ("file_new", O_RDONLY ) != -1 )
		        { write ( 1, "\n", 1 );
		         execlp (“wc", "wc", "-c", "file_new",0 );
                               execlp (“head", "head", "-5c", "file_new",0 );
                              }
	             }
            else {
		    if  (  ( fdr = open ("fileD.txt",O_RDONLY ) ) = = -1 )
		     { printf ("\n Cannot open  \n" );  exit (1);  }
if (( fdw=open ("file_new", O_CREAT|O_TRUNC|O_RDWR,0666 )) == -1 )
		     { printf ("\n Cannot creat  \n" );  exit (1);  }
		     n_byt = read ( fdr , symbols, 40 );
		     c = symbols[ i++];
		     if  ( c >= '0' && c <= '9' )
		      {	while  ( symbols [ i ++] != '\n' && i < n_byt )
                                             write ( fdw, "$", 1 );
                        write ( fdw, "\n", 1 );
                        write ( 1, "\n", 1 );
		       }
		else { write( 1,  symbols, n_byt );  write ( 1, "\n", 1 ); 
                        }
                        write ( fdw, "$\n", 2 );
                        write ( 1, symbols, 12);
                        close ( fdr); close (fdw);
	          }
}
Задача 4  Напишете какво ще бъде изведено на стандартния изход (терминала),  като резултат от изпълнението на файла, получен при успешна компилация на зададения по-долу програмен код на С, в който са използвани системни примитиви на ОС UNIX и LINUX:
                                                                                                                                        
main( )
{    int  a = 2000;
if ( fork()  )  {  a/=2; 
                      printf (“Stoinostta na a = %d\n “, a ) ; 
                   }
else  {  if ( fork() )
            { a*=2;
              printf (“Stoinostta na a = %d\n “, a) ; 
              if  (  execlp(“ps”,“ps”, “-u”,”student”, 0 ) = = -1 ) 
                    {a = a + 2; 
                      printf (“Stoinostta na a = %d\n “, a);   }
             }
           else 
             {   a+=2;
                  printf (“Stoinostta na a = %d\n “, a ) ; }
             }
a++;
printf (“Stoinostta na a = %d\n “, a);  
}


