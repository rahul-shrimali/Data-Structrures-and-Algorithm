#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j;
    for ( i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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
    bubbleSort(a, n);
    printf("Sorted array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}