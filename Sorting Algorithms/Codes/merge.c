#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*) malloc(sizeof(int) * n1);
    int* R = (int*) malloc(sizeof(int) * n2);
    
    for(int i = 0; i < n1; ++i)
        L[i] = arr[l + i];

    for(int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1) 
        arr[k++] = L[i++];

    while(j < n2) 
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    printf("Enter size of the array: ");
    int n; 
    scanf("%d", &n);

    printf("Enter %d elements in the array:\n", n);
    int arr[n];

    for(int i = 0; i < n; ++i ) 
        scanf("%d", arr+i);

    merge_sort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
