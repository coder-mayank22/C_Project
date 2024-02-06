#include<stdio.h>
#define MAX 100
int a[MAX];
void sort(int n){
    int i, j, t, pos;
    for(i=0;i<n-1;i++){
        pos = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[pos]){
                pos = j;
            }
        }
        if(pos!=i){
            t= a[i];
            a[i] = a[pos];
            a[pos] = t;
        }
    }
}

int main(){
    int i, n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter element %d : ", i+1);
        scanf("%d", &a[i]);
    }
    printf("\nArray before sorting : ");
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n\nArray after sorting : ");
    sort(n);
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}