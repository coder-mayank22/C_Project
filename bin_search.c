#include<stdio.h>
#define MAX 100
int a[MAX];

void input(int n){
    printf("Enter values to the array :\n");
    for(int i=0;i<n;i++){
        printf("Enter element %d : ", i+1);
        scanf("%d", &a[i]);
    }
}

void sort(int n){
    int i, j, t, flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                flag=1;
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
        if(flag==0) break;
    }
    printf("\nSorted array : ");
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int b_search(int ele, int n){
    int lb=0, ub=n-1, mid;
    while(lb<=ub){
        mid = (lb+ub)/2;
        if(a[mid]==ele){
            return mid;
        }
        else if(a[mid]>ele) lb=mid+1;
        else ub=mid-1;
    }
    return -1;
}

int main(){
    int n, ele;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    input(n);
    sort(n);
    printf("Enter element to be searched for : ");
    scanf("%d", &ele);
    int pos = b_search(ele,n);
    if(pos==-1){
        printf("%d is not present.\n", ele);
    }
    else{
        printf("%d is present at position %d.\n", ele, pos);
    }
    return 0;
}