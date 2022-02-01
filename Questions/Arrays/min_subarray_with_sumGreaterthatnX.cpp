//Given an array of size n we have to give the minimum size of a subarray whose sum is greater than a value x
/*
Sample input :- a[] = {1, 4, 45, 6, 10, 19} , X = 51
Sample output :- 2
*/

#include<iostream>
using namespace std;

int minSize(int a[], int n, int x){
    int start = 0, sum = 0, ans = n+1;
    for(int i=0; i<n; i++){
        sum += a[i];
        while(start <= i &&  sum > x){
            ans = min(ans, i - start + 1);
            start++;
            sum -= a[start - 1];
        }
    }
    return ans;
}

int main(){
    int a[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    cout<<"Min size is : "<<minSize(a, 6, x);
    return 0;
}