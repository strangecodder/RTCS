#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){
    int fd;
    char message[] = "Третья практика ВСРВ, студент Сухов А.Д.";
    int length = strlen(message);

    fd=open("text.txt", O_CREAT|O_RDWR|O_TRUNC);
    write(fd,message,length);
    
    if(fd == -1){
        printf("Запись не удалась\n");
    }else{
        printf("Запись в файл прошла успешно\n");
    }
}
