// Given two strings find out the length of longest common sub sequence present in both the strings
//Sample input :- s1 = "shubhi" s2 = "rishabh"
//Sample output :- 4 (Explanation = common sub sequence = shbh)
#include<bits/stdc++.h>
using namespace std;

//Memoization technique
int lcs(string s1, string s2, vector<vector<int>> &dp, int n, int m){
    if(n == 0 || m == 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = 1 + lcs(s1, s2, dp, n-1, m-1); 
    }
    else{
        return dp[n][m] = max(lcs(s1, s2, dp, n-1, m), lcs(s1, s2, dp, n, m-1));
    }
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout<<lcs(s1, s2, dp, n, m);
    
    //Tabulation technique
    for(int i=0; i<=n; i++){
        for(int j =0; j<=m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}