//Given an array, you have to find maximum sum of i*a[i]. Where only operation allowed is rotation of array

#include<iostream>
using namespace std;

int max_sum(int *a, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    int curr_sum =0, result = 0;
    for(int i=0; i<n; i++){
        curr_sum += i*a[i];
    }

    result = curr_sum;
    for(int i=1; i<n; i++){
        int next_sum = curr_sum - sum + a[i-1]*n ;  //it is same as a[i-1] + a[i-1]*(n-1)
        curr_sum = next_sum;
        result = max(next_sum, result);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans = max_sum(a, n);
    cout<<"\n"<<ans;
    return 0;
}