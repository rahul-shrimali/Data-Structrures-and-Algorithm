#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto it : adj[src]){
            if(!visited[it] and isCycle(it, adj, visited, stack)) return true;
            if(stack[it]) return true;
        }
    }
    stack[src] = false;
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n );
    vector<bool> visited(n, 0);
    vector<bool> stack(n, 0);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    bool cycle = false;
    for(int i=0; i<n; i++){
        if(!visited[i] and isCycle(i, adj, visited, stack)) {
            cycle = true;
            break;
        }
    }
    if(cycle) cout<<"Cycle present ";
    else cout<<"Cycle not present";
    return 0;
}