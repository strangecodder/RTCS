#include <stdio.h>
#include <fcntl.h>


int main(){
    int fd;
    char message[] = "Третья практика ВСРВ";
    int length = strlen(message);
    fd=open("text.txt", O_CREAT|O_RDWR|O_TRUNC);
    write(fd,message,length);
    printf("Запись в файл прошла успешно\n");
}
