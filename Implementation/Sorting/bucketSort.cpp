#include<bits/stdc++.h>
using namespace std;

void sort(vector<double> a){
    int n = a.size();
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while((j>=0) && (a[j] > key)){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bucketSort(double arr[], int n){
    vector<double> bucket[n];

    for (int i = 0; i < n; i++){
        int index = arr[i]*n;
        bucket[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        sort(bucket[i]);
    }
    
    int in = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <bucket[i].size(); j++){
            arr[in++] = bucket[i][j];
        }
        
    }
    
}

int main(){
    cout<<"\nEnter the size of array : ";
    int n;
    cin>>n;
    double a[n];
    cout<<"Enter the elements of array : (positive) \n";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }

    bucketSort(a, n);

    cout<<"\nSorted array is : ";
    for (int  i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}