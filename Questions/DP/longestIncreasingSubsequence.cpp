//Given an array find the longest increasing subsequence int he array.
//Sample input :- arr[] = {10, 22, 9, 33, 21, 50, 52, 60, 80}
//Sample output :- 7

#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &a, int* dp, int n){
    if(dp[n] != -1){
         return dp[n];
    }

    dp[n] = 1;
    for (int i = 0; i <= n; i++){
        if(a[n] > a[i])
            dp[n] = max(dp[n] , 1+ lis(a, dp, i));
    }

    return dp[n];
    
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }

    int m = INT_MIN;
    for(int i=n-1; i>=0; i--){
        m = max(m, lis(a, dp, i));
    }
    

    cout<< m;
    return 0;
}