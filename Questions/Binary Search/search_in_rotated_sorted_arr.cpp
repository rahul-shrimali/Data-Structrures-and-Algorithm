//Given an array of size n which is sorted and rotated we have to find the position of an key element in that array;
/*
    Sample input :- arr[] = {4, 6, 9, 12, 15, 0, 2, 3}, int key = 9, in case 2 key = 2, in case 3 key = 10
    Sample output = 2, 6, -1
*/

#include<iostream>
using namespace std;

int binarrSrch_inrotatedArray(int a[], int n, int key){
    int start = 0, i = 1;
    while(i<n && a[i] > a[i - 1]){
        i++;
        start++;
    }
    start = start%n;
    int end = n + start - 1;
    while(start <= end){
        int mid = (start + end)/2;
        if(a[mid%n] == key) return mid%n;
        if(a[mid %n] > key) end = mid - 1;
        if(a[mid%n] < key) start = mid +1;
    }
    return -1;
}

int main(){
    int arr[] = {4, 6, 9, 12, 15, 0, 2, 3};
    cout<<binarrSrch_inrotatedArray(arr, 8, 9)<<"\n";
    cout<<binarrSrch_inrotatedArray(arr, 8, 2)<<"\n";
    cout<<binarrSrch_inrotatedArray(arr, 8, 10)<<"\n";

    return 0;
}