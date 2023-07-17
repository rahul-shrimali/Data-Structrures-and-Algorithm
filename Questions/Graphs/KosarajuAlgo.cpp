//Find whether a directed graph is strongly connected (there is a path from each vertex to other vertex or in other words there exists a path between each vertex)

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int src, vector<bool> &vis){
    vis[src] = true;
    for(auto & it: adj[src]){
        if(!vis[it]) dfs(adj, it, vis);
    }
}

vector<vector<int>> find_transpose(vector<vector<int>> &adj){
    vector<vector<int>> transpose(adj.size());
    for(int i =0; i<adj.size(); i++){
        for(auto &it: adj[i]){
            transpose[it].push_back(i);
        }
    }
    return transpose;
}

bool stronglyConnected(vector<vector<int>> &adj){
    vector<bool> vis(adj.size(), false);
    dfs(adj, 0, vis);
    for(int i =0; i<adj.size(); i++){
        if(!vis[i]) return false;
        vis[i] = false;
    }
    vector<vector<int>> graphTranspose = find_transpose(adj);
    dfs(graphTranspose, 0, vis);
    for(int i =0; i<adj.size(); i++){
        if(!vis[i]) return false;
    }
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i =0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    if(stronglyConnected(adj)){
        cout<<"Graph is strongly connected";
    }else{
        cout<<"Graph is not strongly connected";
    }
    return 0;
}