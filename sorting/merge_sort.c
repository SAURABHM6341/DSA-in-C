#include <stdio.h>
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int k = low;
    int j = mid + 1;
    int b[200];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else if (a[i] > a[j])
        {
            b[k++] = a[j++];
        }
        else
        {
            b[k++] = a[i++];
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= high)
    {
        b[k++] = a[j++];
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    // int arr[] = {5,4,3,2,1};
    int arr[] = {15, 8, 0, 9, 1, 7, 6, 19, 5, 3, 2, 4, 6};
    int n = 13;
    printf("unsorted array is \n");
    printarray(arr, n);
    mergesort(arr,0,n-1);
    printf("\nthe sorted array (through bubble sort) is \n");
    printarray(arr, n);

    return 0;
}