#include <stdio.h>
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[(lb + ub) / 2];
    int start = lb;
    int end = ub;
    int temp = 0;
    do
    {
        while (arr[start] < pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start <= end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

    } while ((start <= end));
    return start;
}
void quicksort(int arr[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quicksort(arr, low, partitionindex - 1);
        quicksort(arr, partitionindex, high);
    }
}
int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;
    printf("unsorted array is \n");
    printarray(arr, n);
    quicksort(arr, 0, n - 1);
    printf("\nthe sorted array (through quick sort) is \n");
    printarray(arr, n);

    return 0;
}