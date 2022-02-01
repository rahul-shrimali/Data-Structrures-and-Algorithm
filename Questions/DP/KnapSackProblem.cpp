//Given some items with their weights and corresponding values, you have to choose item such that you can get maximum values where you cannot take items having weight more than W.
//Sample input :- weights = [30, 15, 45]  values = [100, 60, 150]  W = 50
//Sample output :- 160 by tkaing 30, 15
#include<iostream>
using namespace std;

int knapSack(int we[], int val[], int n, int w, int** dp){
    if(n <= 0) return 0;
    if(w <= 0) return 0;

    if(dp[n][w] != -1) return dp[n][w];

    if(we[n-1] > w) return dp[n][w] = knapSack(we,val,  n-1, w, dp);

    return dp[n][w] = max(knapSack(we, val, n-1, w, dp), knapSack(we, val, n-1, w-we[n-1], dp )+ val[n-1]);
}

int main(){
    int n;
    cin>>n;
    int weights[n];
    int values[n];
    for (int i = 0; i < n; i++){
        cin>>weights[i];
    }
    for (int i = 0; i < n; i++){
        cin>>values[i];
    }
    int w;
    cin>>w;

    int** dp = new int*[n+1];
    for (int i = 0; i <= n; i++){
        dp[i] = new int[w+1];
        for(int j =0; j<=w; j++){
            dp[i][j] = -1;
        }
    }
    
    cout<<knapSack(weights, values, n, w, dp);
    return 0;
}