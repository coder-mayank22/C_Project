#include<stdio.h>
#define MAX 100

int a[MAX];
// Sorting method
void sort(int n){
    int i, t, c;
    for(i=1;i<n;i++){
        t=a[i];
        c=i-1;
        while(c>=0 && t<a[c]){
            a[c+1] = a[c];
            c--;
        }
        a[c+1] = t;
    }
}

//Main method
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