#include <stdio.h>
#include <stdlib.h>
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void insertion_sort(int arr[],int n){
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
            else
            {
                break;
            }
            
        }
    }
}

int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
// printf("%d",arr[0]);
    printf("unsorted array is \n");
    printarray(arr, n);
    insertion_sort(arr,n);
    printf("\nsorted array (through insertion sort) is \n");
    printarray(arr, n);
    return 0;
}