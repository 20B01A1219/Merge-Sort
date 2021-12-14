#include <stdio.h>
#include <stdlib.h>
void printarr(int[], int);
void partition(int[], int, int);
void merge(int[], int, int, int);
int main()
{
     int a[10], i, size;
    printf("\nEnter the size of array       : ");
    scanf("%d",&size);
    printf("\nEnter the elements of array    ");
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i = 0;i < size;i++)
    {
        printf("\nEnter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nElements before sorting\t:");
    printarr(a, size);
    partition(a, 0, size-1);
    printf("\nElements after sorting\t:");
    printarr(a, size);
}

void printarr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d \t ", arr[i]);
    }
}

void partition(int arr[], int lb, int ub)
{
    int mid;
    if(lb < ub)
    {
        mid = (lb + ub)/2;
        partition(arr, lb, mid);
        partition(arr, mid+1, ub);
        merge(arr, lb, ub, mid);
    }
}

void merge(int arr[], int lb, int ub, int mid)
{
    int i, j, k , temp[40];
    i = lb;
    j = mid + 1;
    k = lb;
    while(i <= mid && j <= ub)
        {
            if(arr[i] < arr[j])
            {
                temp[k] = arr[i];
                i++;
                k++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
                k++;
            }
        }
    if(i > mid)
    {
        while(j <= ub)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while( i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k = lb; k < ub + 1; k++)
    {
        arr[k] = temp[k];
    }
}
