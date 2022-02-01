//For a given array, find the peak element in the array. Peak element is the one which is greater than both, left and right neighbours of itself
/*
    Sample input - arr[] = {0, 6, 8, 5, 7, 9} 
    Sample output - 8
*/

#include<iostream>
using namespace std;

int peek_index(int a[], int n, int low, int high){
    if(low > high) return -1;
    
    int mid = low + (high - low)/2 ;
    if(((mid == 0) || (a[mid] > a[mid - 1])) && ((mid == n-1) || (a[mid] > a[mid + 1]))){
        return mid;
    }
    else if(mid > 0 && a[mid] < a[mid - 1]){
        return peek_index(a, n, low, mid - 1);
    }
    else{
        return peek_index(a, n, mid + 1, high);
    }
}

int main(){
    int a[] = {0, 6, 8, 5, 7, 9};
    int i = peek_index(a, 6, 0, 5);
    if(i == -1) cout<<"No peek element found in array ";
    else{
        cout<<"Peek element is : "<<a[i];
    }
    return 0;
}