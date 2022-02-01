#include <stdio.h>

void SelectionSort(int a[], int n)
{
    int i, j;
    for ( i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (j = i+1; j < n ; j++)
        {
            if (a[j] < a[min_index]){
                min_index = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
}

int main()
{
    int n, i;
    printf("\nEnter size of Array : \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of Array : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    SelectionSort(a, n);
    printf("Sorted array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}