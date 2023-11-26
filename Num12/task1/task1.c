#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define length 10

int array[length];
int status;
int count_array = 0;
int point =0;
pthread_mutex_t mutex =  PTHREAD_MUTEX_INITIALIZER;


void *producer(void *args);
void *consumer(void *args);
void show_array();

int main(){
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1,NULL,producer,NULL);
    pthread_create(&thread2,NULL,consumer,NULL);

    pthread_join(thread1,&status);
    pthread_join(thread2,&status);

}

void *producer(void *args){
    while(count_array<length){
        
        pthread_mutex_lock(&mutex);
        
        int num = rand()%101;
        
        array[count_array] = num*num;

        printf("Produce: %d\n",num);

        pthread_mutex_unlock(&mutex);

        sleep(1);
        count_array++;
    }
    
    return NULL;
}

void *consumer(void *args){
    while(point<length){

        pthread_mutex_lock(&mutex);

       if(point<count_array){

        while(point!=count_array){
            printf("array[%d] = %d\n",point,array[point]);
            point++;
        }
       }else{
        printf("array[%d] = %d\n",point,array[point]);
        point++;
       }

        pthread_mutex_unlock(&mutex);
       
        sleep(2);
    }
    return NULL;
}