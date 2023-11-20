
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Пока не доделал, при записи в файл выдаёт не понятно что
int main(){
    int fd;
    char *message = (char*) malloc(sizeof(char) * 256);
    char *name = (char*) malloc(sizeof(char)*50);
    printf("Введите название файла: \n");
    scanf("%s",name);
    printf("Введите сообщение, которое хотите записать: \n");
    scanf("%s",message);
    size_t size_m = strlen(message);
    size_t size_n = strlen(name);
    message = (char*) realloc(message,sizeof(int) * size_m);
    name = (char*) realloc(name,sizeof(int) * size_n);
    //int length = strlen(message);
    printf("%d %d",size_m,size_n);
    fd=open(name, O_CREAT|O_RDWR|O_TRUNC,0666);
    write(fd,message,256);
    printf("Запись в файл прошла успешно\n");
    //close(fd);
    //exit(0);
}