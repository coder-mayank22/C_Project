#include<stdio.h>
#define MAX 100
int pivot;

int a[MAX];

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int low, int high) {
  int i,j,t,flag=1,pos=low;
  while(flag == 1){
    for(i=high;i>pos;i--){
        flag = 0;
        if(a[pos]>a[i]){
            swap(&a[pos], &a[i]);
            pos=i;
            flag=1;
            break;
        }
    }
    if(flag == 1){
        for(i=low;i<pos;i++){
            flag = 0;
            if(a[pos]<a[i]){
                swap(&a[pos],&a[i]);
                pos = i;
                flag = 1;
                break;
            }
        }
    }
  }
  return pos;
}
void Quicksort(int lb, int ub){
    if(lb<ub){
        pivot=partition(lb,ub);
        Quicksort(lb,pivot-1);
        Quicksort(pivot+1,ub);
    }
}

int main(){
    int i,size;
    printf("Enter number of elements in the array : ");
    scanf("%d",&size);
    printf("Enter values into the array\n");
    for(i=0;i<size;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n\nArray before sorting :\n");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    //Sorting the array
    
    printf("\n\nArray after sorting :\n");
    Quicksort(0,size-1);
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}