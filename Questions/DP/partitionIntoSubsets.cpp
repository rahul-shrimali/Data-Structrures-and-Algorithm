//Given n peoples and k teams you have to print the number of ways to put these n peoples in k teams
//Example :- 

#include<bits/stdc++.h>
using namespace std;

long long int c = 0;

long long int partition(long long n,long long k, vector<vector<long long>> &dp){
    c++;
    if(n <= 0 || k <= 0) return 0;
    if(n < k) return 0;
    if(n == k) return 1;
    // if(dp[n][k] != -1) cout<<" "<<n<<" "<<k<<" "<<dp[n][k]<<"\n";
    if(dp[n][k] != -1) return dp[n][k];

    return dp[n][k] = k*partition(n-1, k, dp) + partition(n-1, k-1, dp);

}

int main(){
    long long int n, k;
    cin>>n>>k;
    vector<vector<long long>> dp(n +1, vector<long long > (k +1, -1));
    cout<<partition(n, k, dp);
    cout<<"\n"<<c;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<k+1; j++){
    //         c++;
    //         if(j > i){
    //             dp[i][j] = 0;
    //         }else if(j == i){
    //             dp[i][j] = 1;
    //         } else{
    //             dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
    //         }
    //     }
    // }
    // cout<<dp[n][k];
    // cout<<"\n"<<c;
    return 0;
}