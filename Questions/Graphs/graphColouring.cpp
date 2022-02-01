//Given a graph you have to find the minimum number of colours required to color the graph such that no 2 adjacent nodes get the same color

#include<bits/stdc++.h>
using namespace std;
bool done = false;
bool isSafe(vector<vector<int>> &edges, vector<int> &color, int c, int node){
    for(auto it : edges[node]){
        if(color[it] == c){
            return false;
        }
    }
    return true;
}

void colorGraph(vector<vector<int>> &edges, vector<int> &color, int n, int node){
    if(node == n) return;

    for(int c = 1; c<=n; c++){
        if(done) return;
        if(isSafe(edges, color, c, node)){
            color[node] = c;
            if(node+1 < n){
                colorGraph(edges, color, n, node+1);
            }
            else{
                // for(int i=0; i<n; i++){
                //     cout<<color[i]<<" "<<node<<"       ";
                // }
                // cout<<"\n";
                done = true;
                return;
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> color(n, -1); 

    colorGraph(edges, color, n, 0);

    for(int i=0; i<n; i++){
        cout<<color[i]<<" ";
    }
    return 0;
}