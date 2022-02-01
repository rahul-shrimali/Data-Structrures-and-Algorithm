//Given n matrices with their dimensions in a array we have to find the min cost in whihc we can find the multiplication of these matrices 
//Sample input :- p[] = {40, 20, 30, 10, 30}   
//Output :- 26000 
/*There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    // cin>>n;
    vector<int> arr = {6, 4, 3, 5, 2};
    // for(int i=0; i<n; i++)
    //     cin>>arr[i];
    
    vector<vector<int>> dp(n - 1, vector<int> (n - 1, 0));

    for(int g=0; g<n - 1; g++){
        for(int i=0, j = g; j<n - 1; i++, j++){
            if(g == 0){
                dp[i][j] = 0;
            } else if(g == 1){
                dp[i][j] =  arr[i]*arr[j] * arr[j+1];
            }
            else{
                int min = INT_MAX;
                for(int k =i; k<j; k++){
                    int lc = dp[i][k];
                    int rc = dp[k+1][j];
                    int mc = arr[i]*arr[k+1]*arr[j+1];
                    int tc = lc + rc + mc;
                    if(tc < min) min = tc;
                }
                dp[i][j] = min;
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j =i; j<n-1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}