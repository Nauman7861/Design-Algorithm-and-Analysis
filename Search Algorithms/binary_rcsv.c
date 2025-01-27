#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search(arr, mid + 1, high, target);
    } else {
        return binary_search(arr, low, mid - 1, target);
    }
}

int main() {
    int arr[] = {3,14,56,87,909,1211,2321};
    printf("Array : ");
    for(int i = 0; i<7; i++)
      printf("%d ", arr[i]);
    int target;
    printf("\nChoose the element from the above array to be searched ");
    scanf("%d",&target);
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = binary_search(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element is not present in array.\n");
    } else {
        printf("Element is present at index %d.\n", result);
    }
    return 0;
}