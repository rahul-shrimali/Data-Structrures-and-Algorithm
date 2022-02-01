//Given a 2D matrix consists of cost to go thorw that cell of matrix. Find out the minimum cost to travel from 0, 0 cell to n, m cell
#include<bits/stdc++.h>
using namespace std;

int minCost(int** arr, vector<vector<int>> &dp, int i, int j, int n, int m){
    if((i >= n && j >= m-1) || (i>= n-1 && j >=m)) return 0;
    if(i >= n || j >= m) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = arr[i][j] + min(minCost(arr, dp, i+1, j, n, m), minCost(arr, dp, i, j+1, n, m));

}

int main(){
    int n, m;
    cin>>n>>m;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> (m));
    
    //Memoization 
    // cout<<minCost(arr, dp, 0, 0, n, m);

    //Tabulation
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if( i== n-1 && j == m-1)
                dp[i][j] = arr[i][j];
            else if(i == n-1){
                dp[i][j] = arr[i][j] + dp[i][j+1];
            }
            else if (j == m-1){
                dp[i][j] = arr[i][j] + dp[i+1][j];
            }
            else{
                dp[i][j] = arr[i][j]  + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0];
    return 0;
}