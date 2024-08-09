#include <stdio.h>
void maxheapify(long long int a[], long long int n, long long int i)
{
     long long int largest = i;
     long long int l = (2 * i)+1;
     long long int r = l + 1;
    while (l <= n-1 && a[l] > a[largest])
    {
        largest = l;
    }
    while (r <= n-1 && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        long long int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxheapify(a, n, largest);
    }
}
void heapsort(long long int a[], long long int n)
{
    for ( long long int i = (n / 2) - 1; i >= 0; i--)
    {
        maxheapify(a, n, i);
    }
    for ( long long int i = n - 1; i >= 0; i--)
    {
          long long int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxheapify(a, i, 0);
    }
}
int main()
{
     long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for ( long long int i = 0; i < n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    
    // printf("unsorted  array is \n");
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    heapsort(arr, n);
    printf("sorted array is \n");
    for (long long int i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }

    return 0;
}