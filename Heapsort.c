#include<stdio.h>

int arr[100],size;

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void inputarray(){
    printf("Enter number of elements in the array : ");
    scanf("%d",&size);

    printf("\nEnter %d values to the array :\n",size);

    for(int i=0;i<size;i++){
        printf("Element %d : ",i+1);
        scanf("%d",&arr[i]);
        //printf("%d",arr[i]);
    }
}

void heapify(int N, int i)
{
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
    largest = left;
 
    if (right < N && arr[right] > arr[largest])
    largest = right;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(N, largest);
    }
}

void heapSort(int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
    heapify(N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        // Heapify root element
        // to get highest element at
        // root again
        heapify(i,0);
    }
}

void printarray(){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    //Input the array
    inputarray();

    printf("Array before sorting :\n");
    printarray();

    printf("Array after sorting :\n");
    heapSort(size);
    printarray();

    return 0;
}
 
