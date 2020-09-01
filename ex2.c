#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
        }
    }
}

int main(){
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int* arr=(int*)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}