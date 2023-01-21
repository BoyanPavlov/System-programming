ИМЕ ..............................................................фак. № …………адм. гр. .....

К О Н Т Р О Л Н О 
Системно програмиране


Задача 1   Да се напише програма на C, която ползвайки системните примитиви за работа с файлове и процеси в Linux,  получава като параметри на командния ред две команди, като първата е без параметри. Изпълнява ги едновременно. Чака приключването на всяка една от тях и извежда кода й на завършване и номера на завършилия процес.

Задача 2. В текущия каталог се намира текстов файл abc със следното съдържание :
Let’s go change the world!
Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С :

main( )
{int fdi, fdio, nb1, nb2;
char buff [ 15 ] ;	
	fdi = open ( “ abc”, O_RDONLY);
            fdio = open ( “ abc”, O_RDWR);
 
            nb1= read( fdi,buf,6);
            write ( 1, buf, nb1);

           lseek( fdi,3,SEEK_CUR);
           nb1= read( fdi,buf,6);
           write ( 1, buf, nb1);

           lseek( fdio,-18, SEEK_END);
	   write( fdio,”tra”,3);

           write( fdio,”vel”,3);
           nb2=read( fdio,buf,5);
           write ( 1, buf, nb2);
           write ( 1,”time”, 4);

           lseek( fdi,-2,SEEK_END);
           nb2= read( fdi,buf,2);
           write ( 1, buf, nb2)
Задача 3 Като първи параметър на програма на С се подава съществуващ празен файл. Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С :


#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>
main ( int argc, char *argv[] )
{
	int fd, i, status;
            if ( fork() )
           { wait(&status);
             for ( i=0; i<=3; i++)
            { write ( 1, “cal\n”,4);
               execlp ( “cal”, “cal”, 0);
               write ( 1, “hello1\n”,6); }
             }
            else { close(1);
                     fd = open ( argv[1], O_RDWR) ;
                 write (1, “hello2\n”,6);}
write (1, “hello3\n”,6);
}


Задача  4  Да се напише програма на C, която получава 2 параметъра – имена на файлове. Стартира команда тръсеща срещането на низ pts, като пренасочва стандартния й вход от първия файл, а стандартния й изход и изхода й за грешки - във втория. Накрая извежда кода й на завършване на екрана.
