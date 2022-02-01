//Given an array of size n we have to find the max sum subarray of size k whose sum is less than x
/* 
    Sample Input :- a[] = {7, 5, 4, 6, 8, 9} k =3 , x = 20
    ans = 18
*/

#include<iostream>
using namespace std;

int slidingWindow(int a[], int n, int k, int x){
    int sum = 0, ans = 0;
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    if(sum < x) ans = sum;
    for(int i = k; i<n; i++){
        sum -= a[i-k];
        sum += a[i];
        if(sum < x) ans = max(ans, sum); 
    }
    return ans;
}

int main(){
    int a[] = {7, 5, 4, 6, 8, 9};
    int k = 3, x = 20;
    cout<<"Max sum is : "<<slidingWindow(a, 6, k, x);
    return 0;
}