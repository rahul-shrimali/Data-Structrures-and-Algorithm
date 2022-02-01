/*
    Give a 2D matrix in which row means house number and col means color and a[r][c] contains cost of coloring that house with that color.
    You have to find the minimum cost of painting all houses such that no two adjacent houses have same color
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> (m, INT_MAX));
    //This approach do in O(n^3) optimization is below
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(i != 0){
    //             int ma = INT_MAX;
    //             for(int k = 0; k<m; k++){
    //                 if(k != j) ma = min(ma, dp[i-1][k]);
    //             }
    //             // cout<<i<<" is i "<<j<<" is j "<<m<<"\n";
    //             dp[i][j] = a[i][j] + ma;
    //         }else{
    //             dp[i][j] = a[i][j];
    //         }
    //     }
    // }
    
    int least = INT_MAX, second_least = INT_MAX;
    for(int j=0; j<m; j++){
        dp[0][j] = a[0][j];
        if(a[0][j] <= least){
            second_least = least;
            least = a[0][j];
        } else if (a[0][j] < second_least){
            second_least = a[0][j];
        }
    }

    for(int i=1; i<n; i++){
        int l = least;
        int sl = second_least;
        least = INT_MAX;
        second_least = INT_MAX;
        for(int j =0; j<m; j++){
            if(dp[i-1][j] == l){
                dp[i][j] = a[i][j] + sl;
            }else {
                dp[i][j] = a[i][j] + l;
            }

            if(dp[i][j] <= least){
                second_least = least;
                least = dp[i][j];
            } else if (dp[i][j] < second_least){
                second_least = dp[i][j];
            }
        }
    }
   
    cout<<least;
    return 0;
}