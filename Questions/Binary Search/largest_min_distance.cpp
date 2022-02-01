//Given is an array with n elements that reperesents n positions along a straight line. Find K elements such that the minimum distance between any 2 elements is the maximum Possible
/*
    Sample input :- a[] = {11, 2, 7, 5, 1, 12}, k = 3
    Sample Output :- 5
    Explanation - As we have to take a subarray of size 3 the largest min distance is found in subarray {1, 7, 12} and its min distance is 5
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
    int curr = 1, pos = arr[0];
    for(int i =1; i<n; i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            curr++;
            if(curr == k) return true;
        }
    }
    return false;
}

int largest_min_distance(int arr[], int n, int k){
    sort(arr, arr+n);
    int left = 1, right = arr[n-1];
    int mid = (left + right)/2, ans = 0;
    while(left < right){
        if(isFeasible(mid, arr, n, k)){
            ans = max(ans, mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
        mid = (left + right)/2;
    }

    return ans;
}

int main(){
    int arr[] = {11, 2, 7, 5, 1, 12};
    int k = 3;
    cout<<"Largest minimum distance in above case is : "<<largest_min_distance(arr, 6, k);
    return 0;
}