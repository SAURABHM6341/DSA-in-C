#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    if (left < n && ((isMaxHeap && arr[left] > arr[largest]) || (!isMaxHeap && arr[left] < arr[largest])))
        largest = left;
    if (right < n && ((isMaxHeap && arr[right] > arr[largest]) || (!isMaxHeap && arr[right] < arr[largest])))
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, isMaxHeap);
    }
}
void heapSort(int arr[], int n, int isMaxHeap) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[] = { 10,15,40,5,12,24,8,6,9,2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    heapSort(arr, n, 1);
    printf("\nArray sorted in Max Heap Order: \n");
    printArray(arr, n);
    heapSort(arr, n, 0);
    printf("\nArray sorted in Min Heap Order: \n");
    printArray(arr, n);
    return 0;
}