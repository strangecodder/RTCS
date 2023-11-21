#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COUNT  200

void ParentProcess();
void ChildProcess();

int main(){
    int pd;
    pd = fork();
    if(pd != 0 ){
        ParentProcess();
        
    }else{
        ChildProcess();
    }
    return 0;
}

void ParentProcess(){
    for(int i = 0; i < MAX_COUNT; i++)
    {
        printf("Эта линия из родительского процесса где i = %d \n",i);
    }
}

void ChildProcess(){
    for(int i = 0; i < MAX_COUNT; i++)
    {
        printf("Эта линия из дочернего процесса где i = %d \n",i);
    }
}