//This algo is the alternative for dijkshitr's algo where we have both negative as well as posotive edges.
//In this also we find the shortest path from a source node to all other edges 
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int> > edges;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
        // edges.push_back({v, u, w});
    }

    //BellmanFord Algo goes here

    vector<int> dist(n, INF);
    dist[5] = 0;

    for(int i= 0; i<n; i++){
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for(int i=0; i<n; i++){
        if(dist[i] < 1e5) cout<<dist[i]<<" ";
        else cout<<"-1 ";
    }
    return 0;
}