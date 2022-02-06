#include<iostream>
using namespace std;

void countSort(int arr[], int exp, int n){
    
    int counting[10] = {0};
    for (int i = 0; i < n; i++){
        int pos = (arr[i]/exp) % 10;
        counting[pos]++;
    }

    for(int i =1; i<10; i++){
        counting[i] += counting[i-1];
    }

    int result[n];
    for (int i = n-1; i >= 0; i--){
        int pos = (arr[i]/exp) % 10;
        result[--counting[pos]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = result[i];
    }
    
}


void radixSort(int arr[], int n){
    int max = INT_MIN;
    for (int  i = 0; i < n; i++){
        if (arr[i] > max) max = arr[i];
    }
    
    int l = to_string(max).length();
    int exp = 1;
    for(int i=0; i<l; i++){
        countSort(arr, exp, n);
        exp *= 10;
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

    radixSort(a, n);

    cout<<"\nSorted array is : ";
    for (int  i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    
    cout<<"\n";
    return 0;
}