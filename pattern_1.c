#include<stdio.h>
int n;

int main(){
    printf("Enter no. of rows : ");
    scanf("%d",&n);
    int i,j,c;
    for(i=1;i<=n;i++){
        c=n-i+1;
        for(j=1;j<=i;j++)
            printf("%d",c++);
        for(int k=i+1;k<=n;k++)
            printf("%d",n);
        printf("\n");
    }
    return 0;
}