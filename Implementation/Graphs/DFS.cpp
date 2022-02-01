#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool visited[N] = {0};

void dfs(int node){
    visited[node] = 1;
    //preorder
    cout<<node<<" ";
    //Inorder
    vector<int> :: iterator it;
    
    for(it = adj[node].begin(); it != adj[node].end(); it++){
        if(!visited[*it]) dfs(*it);
    }

    //for post order just print node here not above
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    return 0;
}