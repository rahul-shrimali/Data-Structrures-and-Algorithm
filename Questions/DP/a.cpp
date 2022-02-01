#include<bits/stdc++.h>
using namespace std;

int gold(vector<vector<int>> &arr, vector<vector<int>> &dp, int row, int col, int n){
    if(row < 0 || col < 0) return 0;
    // cout<<"Running "<<row<<" "<<col<<" "<<arr[row][col]<<"\n";
    if(row>=n || col >= n){
        // cout<<"\nreturned in col>=n";
        return 0;
    }
    
    if(col == n-1) {
        // cout<<"\nReturned in col == n-1";
        return dp[row][col] = arr[row][col];
    }
    
    if(dp[row][col] != -1){
        // cout<<"\nreturne din not -1";
        return dp[row][col];
    } 
    return dp[row][col] = arr[row][col] + max(max(gold(arr, dp, row + 1, col + 1, n), gold(arr, dp, row-1, col + 1, n)), gold(arr, dp, row, col+1, n)); 
}

int main(){
    int n = 6;
    vector<vector<int>> arr {
        {0, 1, 4, 2, 8, 2},
        {4, 3, 6, 5, 0, 4},
        {1, 2, 4, 1, 4, 6},
        {2, 0, 7, 3, 2, 2},
        {3, 1, 5, 9, 2, 4},
        {2, 7, 0, 8, 5, 1}
    };
    vector<vector<int>> dp(n, vector<int> (n, -1));
    int m = 0;
    for(int i=0; i<n; i++){
        cout<<"\ni os "<<i;
        m = max(m, gold(arr, dp, i, 0, n));
    }
    cout<<m;
    return 0;
}