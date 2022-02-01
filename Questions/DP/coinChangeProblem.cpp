//Given a sum of amount and the number of coins available in market you have to show the total number of ways to take coins such that it sum up to the amount.
//Sample input :- S[] = {1, 3, 2}  value = 6, 
//Output :- 7 
//Explanation :- YOu can take following combinations - {3, 3}, {3, 2, 1}, {2, 2, 2}, {2, 2, 1, 1}, {2, 1, 1, 1, 1}, {3, 1, 1, 1}, {1, 1, 1, 1, 1, 1}

#include<bits/stdc++.h>
using namespace std;

//This memoization takes a space complexity of O(n*m)
int coinChange(vector<int> &s, int n, int val, vector<vector<int>> &dp){
    if(val < 0) return 0;
    if(val == 0) return 1;
    if(n <= 0) return 0;

    if(dp[n][val] != -1) return dp[n][val];

    return dp[n][val] = coinChange(s, n, val-s[n-1], dp) + coinChange(s, n-1, val, dp); 
}

int main(){
    int n;
    cin>>n;
    vector<int> s(n);
    for (int i = 0; i < n; i++){
        cin>>s[i];
    }
    
    int value;
    cin>>value;

    //making a space of O(n*m) for memoization
        // vector<vector<int>> dp(n+1, vector<int> (value+1, -1));
        // for(int i=0; i<n; i++)
        //     dp[i][0] = 1;

        // cout<<coinChange(s, n, value, dp);

    //We have one more way of tabulation which takes space only of O(m);
        vector<int> dp(value+ 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++){
            for(int j = s[i]; j<=value; j++){
                dp[j] += dp[j-s[i]];  //It just combines whether to leave or take because if we leave we have the upper case and to take the coin we add the case of the remaining amount
            }
        }
        
        cout<<dp[value];
    return 0;
}