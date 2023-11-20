#include <fcntl.h>
#include <stdio.h>

 void redirect_stdout(char *);
 main(){
/* printf выводит на standard output*/
  printf("Hello world\n");               
  fflush(stdout);
/*перенаправление standard output*/
  redirect_stdout("foo");
  printf("Hello to you too, foo\n");
/*printf  выводит в файл foo */
  fflush(stdout);
 }

  void redirect_stdout(char *filename){
    int fd;
    /*open a new file */
    if ((fd = open(filename,O_CREAT|O_WRONLY,0666)) < 0){
      perror(filename);
      exit(1);
       }
    close(1);             /*close old standard output*/
    if (dup(fd) !=1){  /*dup new fd to *standard input*/
        fprintf(stderr,"Unexpected dup failure\n");
    exit(1);
      }
/*close первоначальный, new fd, он больше не нужен*/
   close(fd);     
 }
