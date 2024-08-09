#include <stdio.h>
#include <stdlib.h>
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
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
    printf("unsorted array is \n");
    printarray(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
            index = j;//which index has mini value so that we can swap them
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    printf("\nsorted array (through selection sort) is\n");
    printarray(arr, n);
    return 0;
}