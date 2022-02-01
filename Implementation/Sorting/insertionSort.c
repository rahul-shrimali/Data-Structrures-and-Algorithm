#include<stdio.h>

void insertionSort(int *a, int n){
    int i;
    for(i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while((j>=0) && (a[j] > key)){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int n, i;
    printf("\nEnter size of Array : \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of Array : \n");
    for( i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    printf("Sorted array is : \n");
    for( i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}