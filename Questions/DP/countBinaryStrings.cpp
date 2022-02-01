/*
    Given a number n you have to count number of binary string possible of size n such that there are no 2 consecutive 0' s
*/

#include<bits/stdc++.h>
using namespace std;
int steps = 0;
int binary(vector<vector<int>> &dp, int n, int prev){
    steps++;
    if(n <= 0) return 1;
    if(dp[n][prev] != -1) return dp[n][prev];
    if(prev == 0){
        return dp[n][prev] = binary(dp, n-1, 1);
    } 
    else return dp[n][prev] = binary(dp, n-1, 1) + binary(dp, n-1, 0);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n+1, vector<int> (2, -1));
    cout<<binary(dp, n, 1)<<" "<<steps;
    return 0;
}