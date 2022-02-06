#include<iostream>
using namespace std;

void countSort(int arr[], int n){
    int max = INT_MIN;
    for (int  i = 0; i < n; i++){
        if (arr[i] > max) max = arr[i];
    }
    
    int counting[max + 1] = {0};
    for (int i = 0; i < n; i++){
        counting[arr[i]]++;
    }

    for(int i =1; i<=max; i++){
        counting[i] += counting[i-1];
    }

    int result[n];
    for (int i = n-1; i >= 0; i--){
        result[--counting[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = result[i];
    }
    
}

int main(){
    cout<<"\nEnter the size of array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array : (positive integers : ) \n";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    countSort(a, n);

    cout<<"\nSorted array is : ";
    for (int  i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}