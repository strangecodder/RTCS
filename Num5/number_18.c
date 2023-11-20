#include <stdio.h>

struct vector{
    double x;
    double y;
    double z;
};

double determinant(struct vector V1, struct vector V2, struct vector V3);
double parallelepiped_Volume(struct vector V1, struct vector V2, struct vector V3);
double pyramid_Volume(struct vector V1, struct vector V2, struct vector V3);

int main(){
    struct vector V[3];
    printf("Введите координаты 3-х векторов: ");
    for(int i = 0; i< 3; i++){
        printf("%s%d%s","Вектор №",i+1,":\n");
        double x;
	double y;
	double z;
        scanf("%f",x);
	scanf("%f",y);
	scanf("%f",z);
	struct vector Vec = {x,y,z};
       	V[i] = Vec;
    }
//    struct vector V1 = {-2.0 , -6.0, 1.0}; 
  //  struct vector V2 = {4.0 , -3.0, -2.0}; 
   // struct vector V3 = {-4.0, -2.0, 2.0}; 

    printf("%s%f%s","Результат произведения векторов: ",determinant(V[0],V[1],V[2]),"\n");
    printf("%s%f%s","Объем параллелепипеда: ",parallelepiped_Volume(V[0],V[1],V[2]),"\n");
    printf("%s%f%s","Объем пирамиды: ",pyramid_Volume(V[0],V[1],V[2]),"\n");
    return 0;
}

double determinant(struct vector V1, struct vector V2, struct vector V3){
    double r1,r2,r3;
    r1 = V1.x * ((V2.y * V3.z) - (V3.y * V2.z));
    r2 = (-1) * V1.y * ((V2.x * V3.z) - (V3.x * V2.z));
    r3 = V1.z * ((V2.x * V3.y) - (V3.x * V2.y));
    return r1-r2+r3;
}

double parallelepiped_Volume(struct vector V1, struct vector V2, struct vector V3){
    double result = determinant(V1,V2,V3);
    if(result<0){
        return (-1) * result;
    }else{
        return result;
    }
}

double pyramid_Volume(struct vector V1, struct vector V2, struct vector V3){
    return 1/6 * determinant(V1,V2,V3);
}
