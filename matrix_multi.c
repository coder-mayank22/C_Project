#include<stdio.h>
#define MAX 100

int a[MAX][MAX], b[MAX][MAX];

void input(int x, int y, int z){
    int i, j, c=1;
    printf("Enter %d values for matrix A :\n", x*y);
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("Enter element %d : ", c++);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Matrix A :\n\n");
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter %d elements for matrix B :\n", y*z);
    c=1;
    for(i=0;i<y;i++){
        for(j=0;j<z;j++){
            printf("Enter element %d : ", c++);
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrix B :\n");
    for(i=0;i<y;i++){
        for(j=0;j<z;j++)printf("%d\t", b[i][j]);
        printf("\n");
    }
}

void multiply(int x, int y, int z){
    int c[x][z];
    int i, j, k1=0, k2=0, col, s;
    for(i=0;i<x;i++){
        col=0;
        while(col<z){
            s=0;
            for(j=0;j<y;j++){
                s = s+(a[i][j]*b[j][col]);
            }
            col++;
            if(k2<z){
                c[k1][k2] = s;
            }
            else{
                k1++;
                k2=0;
                c[k1][k2]=s;
            }
            k2++;
        }
    }

    for(i=0;i<x;i++){
        for(j=0;j<z;j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int x, y, y1, z;
    printf("Enter number of rows of matrix A : ");
    scanf("%d", &x);
    printf("Enter number of columns of matrix A : ");
    scanf("%d", &y);
    printf("Enter number of rows of matrix B : ");
    scanf("%d", &y1);
    printf("Enter number of columns of matrix B : ");
    scanf("%d", &z);
    if(y!=y1){
        printf("Matrix Multiplication is not possible.\n");
    }
    else{
        input(x,y,z);
        printf("Resultant matrix :\n");
        multiply(x,y,z);
    }
    return 0;
}