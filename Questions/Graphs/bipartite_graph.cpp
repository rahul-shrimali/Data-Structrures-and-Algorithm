/*
    A graph is called as bipartite graph if -
    (i) Its vertices can be divided into two disjoint and independent sets U nad V such that every edge connects a vertex in U to one in V.
    (ii) The graph does not contain any odd length cycles 
    (iii) The graph is 2 colorable
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool color(int curr, vector<vector<int>> &adj, vector<int> &col, int c){
    if(col[curr] != -1 and col[curr] != c) return false;
    if(col[curr] != -1) return true;
    col[curr] = c;
    for(auto it : adj[curr]){
       
            if(!color(it, adj, col, 1^c)) return false; 
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> col(n, -1);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool bipartrate = true;
    for(int i=0; i<n; i++){
        if(col[i] == -1){
            bipartrate = color(i, adj, col, 0);
        }
    }
    if(bipartrate) cout<<"Bipartate";
    else cout<<"Not bipartate";
    return 0;
}