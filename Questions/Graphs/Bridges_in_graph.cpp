//given a graph find all the bridges in the  graph 
// this algo is also known as  tarjan algo 

#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &adj, vector<bool> &vis, vector<int>&time, vector<int>&min_time, int src, int parent, int &t, vector<vector<int>> &res){
    vis[src]=  true;
    time[src] = t;
    min_time[src] = min(min_time[src], t);
    t++;
    for(auto it : adj[src]){
        if(!vis[it]){
            solve(adj, vis, time, min_time, it, src, t, res);
            if(min_time[it] > time[src]){
                res.push_back({src, it});
            }
        }
        
        if(it != parent){
            min_time[src] = min(min_time[src], min_time[it]);
        }
    }
        
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> res;
    vector<vector<int>> adj(n);
    for(int i =0; i<connections.size(); i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    vector<bool> vis(n, false);
    vector<int> time(n, INT_MAX);
    vector<int> min_time(n, INT_MAX);
    int t = 1;
    solve(adj, vis, time, min_time, 0, -1, t, res);
    return res;
}

int main(){
    
    return 0;
}