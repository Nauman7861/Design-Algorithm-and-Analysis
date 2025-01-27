#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main(){
   int i, n, arr[25];
   printf("Enter size of the array: ");
   scanf("%d",&n);
   printf("Enter %d elements: ", n);
   for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
   quick_sort(arr,0,n-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
   printf(" %d",arr[i]); 
   return 0;
}