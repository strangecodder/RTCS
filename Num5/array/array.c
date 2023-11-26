#include <stdio.h>
#include <stdlib.h>

void show_array(int array[],int n);

int main(){
    int N;
    int *arr;
    printf("Введите N: ");
    scanf("%d",&N);
    arr = (int *)malloc(sizeof(int) * N);
    for(int i = 0;i < N;i++){
        scanf("%d",&arr[i]);
    }
    show_array(arr, N);

}

void show_array(int array[],int n){
    for(int i = 0;i < n; i++){
        printf("arr[%d] = %d \n",i,array[i]);
    }
}