#include <stdio.h>
#include <stdlib.h>
void printarray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
int main()
{
    int n;
    printf("enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    int a =0;
    printf("enter the array element\n");
    for (int i = 0; i <= n-1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("unsorted array is \n");
    printarray(arr,n);
   while(1)
    {
        int b =0;//if array is sorted at any pass 1st 2nd or any other break it
        for (int j = 0; j < n-1-a; j++)//j wali cheez for no. of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                b=1;
            }
        }
        a++;//ye number of passes ke liye
        if (b==0)
        {
            break;
        }
        
    }
    printf("\nsorted array (through bubble sort) is \n");
    printarray(arr,n);

    return 0;
}