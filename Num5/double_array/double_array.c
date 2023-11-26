#include <stdio.h>
#include <stdlib.h>

void show_doubleArray(int **array,int n,int m);
int** push_to_array(int **array, int n, int m);

int main(){
    int n,m;
    int **array;

    printf("Введите количество строк: ");
    scanf("%d",&n);
    printf("Введите количество столбцов: ");
    scanf("%d",&m);

    array = push_to_array(array,  n,  m);

    printf("\n");
    show_doubleArray(array, n, m);

    free(array);
}

void show_doubleArray(int **array,int n, int m){
    for (int i = 0;i < n; i++ ){
    
        printf("|| ");
    
        for(int j = 0; j < m;j++){
    
            printf("%d ",array[i][j]);
    
        }
    
        printf("||\n");
    }
}

int** push_to_array(int **array, int n, int m){
    array = (int **)malloc(sizeof(int) *n);

    for(int i = 0; i < n; i++){
        
        array[i] = (int*) malloc(sizeof(int) * m);

        for(int j = 0 ; j < m; j++){
        
            printf("array[%d][%d] = ",i,j);
            scanf("%d",&array[i][j]);
        
        }
    }
    return array;
}