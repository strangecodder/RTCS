
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int fd;
    // выделяем память массивам message и name
    char *message = (char*) malloc(sizeof(int) * 2); 
    char *name = (char*) malloc(sizeof(int)* 2);


    printf("Введите название файла: \n");
    scanf("%[^\n]%*c",name); //%*с обрабатывает символ и отбрасывает его (в моём случае - перенос на другую строку)
    printf("Введите сообщение, которое хотите записать: \n");
    scanf("%[^\n]%*c",message);

    fd=open(name, O_CREAT|O_RDWR|O_TRUNC,0666);

    int size_m = strlen(message);
    write(fd,message,size_m);

    printf("Запись в файл прошла успешно\n");
}