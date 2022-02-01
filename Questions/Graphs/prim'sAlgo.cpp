/*
    Given an undirected and connected graph G(v, e), a spanning tree of graph G is a tree that spans G(i.e. includes every vertex of G) and is a subgraph of G
    The cost of spanning tree is the sum of the weights of all edges in the tree
    Find the minimum cost of a spanning tree
*/

#include<bits/stdc++.h>
using namespace std;

void prims(vector<vector<int>> adj[], vector<bool> &visited, int &ans){
    set<vector<int>> s;
    s.insert({0, 0});
    visited[0] = true;
    while(!s.empty()){
        auto a = *(s.begin());
        s.erase(a);
        if(!visited[a[1]]) ans += a[0];
        visited[a[1]] = true;
        for(auto it : adj[a[1]]){
            if(visited[it[1]]){
                continue;
            }
            else {
                s.insert({it[0], it[1]});
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj[n];
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }    
    int ans = 0;
    vector<bool> visited(n, 0);
    prims(adj, visited, ans);
    cout<<ans<<" ";
    return 0;
}