//Representation of graph through adjacency matrix
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int main(){
    int n, m; //n is total number of elements and m total number of edges
    cin >> n >> m;
    vector<vector<int>> adjM(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adjM[x][y] = 1;
        adjM[y][x] = 1;
    }
    cout<<"matrix representation is : \n";
    for(int i=1; i<=n; i++){
        for(int j =1; j<=n; j++)
            cout<<adjM[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}