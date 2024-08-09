#include <stdio.h>
#include <stdlib.h>
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}
void bubblesort(int arr[], int n)
{
    int a = 0;
    while (1)
    {
        int b = 0;                          // if array is sorted at any pass 1st 2nd or any other break it
        for (int j = 0; j < n - 1 - a; j++) // j wali cheez for no. of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                b = 1;
            }
        }
        a++; // ye number of passes ke liye
        if (a == n - 1 || b == 0)
        {
            break;
        }
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
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j; // which index has mini value so that we can swap them
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int main()
{
   int arr[] = {15, 8, 0, 9, 1, 7, 6, 19, 5, 3, 2, 4, 6};
    int n = 13;
    printf("unsorted array is \n");
    printarray(arr, n);
    bubblesort(arr, n);
    printf("\nsorted array (through bubble sort) is \n");
    printarray(arr, n);
    insertion_sort(arr, n);
    printf("\nsorted array (through insertion sort) is \n");
    printarray(arr, n);
    selection_sort(arr, n);
    printf("\nsorted array (through selection sort) is\n");
    printarray(arr, n);
    quicksort(arr, 0, n - 1);
    printf("\nthe sorted array (through quick sort) is \n");
    printarray(arr, n);
    mergesort(arr, 0, n - 1);
    printf("\nthe sorted array (through merge sort) is \n");
    printarray(arr, n);
    return 0;
}