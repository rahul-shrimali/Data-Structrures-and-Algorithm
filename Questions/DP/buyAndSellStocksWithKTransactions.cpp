/*
    Given a Array of prices of Stocks on particular days and a number 
    you can make total of k transactions (One transaction contains a buying and a selling).
    You have to do transactions such that profit is maximized 

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> stocks(n);
    for(int i=0; i<n; i++){
        cin>>stocks[i];
    }

    int k;
    cin>>k;

    vector<vector<int>> dp(k+1, vector<int> (n, 0));
    
    // //Brute Force approach
    // for(int t = 1; t<=k; t++){
    //     for(int d = 1; d<n; d++){
    //         int ma = dp[t][d-1];
    //         for(int pd = 0; pd < d; pd++){
    //             ma = max(ma,  stocks[d] - stocks[pd] + dp[t-1][pd] );
    //         }
    //         dp[t][d] = ma;
    //     }
    // }

    for(int i=1; i<=k; i++){
        int ma = INT_MIN;
        for(int j = 1; j<n; j++){
            ma = max(ma, dp[i-1][j-1] - stocks[j-1]);
            dp[i][j] = max(ma + stocks[j], dp[i][j-1]);
        }
    }

    cout<<dp[k][n-1];
    return 0;
}