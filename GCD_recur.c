#include<stdio.h>
int gcd(int a, int b){
    if(a>b){
        gcd(a-b,b);
    }
    else if(a<b){
        gcd(a,b-a);
    }
    else return a;
}
int main(){
    int x,y;
    printf("Enter 1st number : ");
    scanf("%d", &x);
    printf("Enter 2nd number : ");
    scanf("%d", &y);
    int GCD = gcd(x,y);
    printf("\nGCD of %d and %d = %d\n",x,y,GCD);
    return 0;
}