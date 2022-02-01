//Given a number find the minimum number of squares which can add upto that given number 
// Sample input :- n = 3028 Sample output = 2 (i.e. sum 3024(32sq.) + 4);

#include<bits/stdc++.h>
using namespace std;

int minSquares(int n, vector<int> & dp){
    if(n <= 3) return n;

    if(dp[n] != INT_MAX) return dp[n];

    for(int i=1; i*i <= n; i++){
        dp[n] = min(dp[n], minSquares(n- i*i, dp) + 1);
    }

    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n + 1, INT_MAX);

    cout<<minSquares(n, dp);
    return 0;
}