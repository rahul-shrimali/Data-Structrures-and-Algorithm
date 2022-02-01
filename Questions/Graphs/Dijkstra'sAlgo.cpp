/*
    Given a weighted graph. Find the single source shortest path from a vertex u to all the vertices in the graph. If the node is unreachable, then print -1;
    
    Weight of each node must be positive for this algo to work;
*/

#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;


int main(){
    int n , m;
    cout<<"\nEnter total vertices : ";
    cin>>n;
    cout<<"Enter total number of edges : ";
    cin>>m;
    vector<int> dist(n, inf);
    vector<vector<int>> edges[n];
    for(int i=0; i<m; i++){
        cout<<"Enter vertex1, vertex2, distance : ";
        int u, v, w;
        cin>>u>>v>>w;
        edges[u].push_back({w, v});
        edges[v].push_back({w, u});
    }
    //Having  a visited in dijistra reduces time complexity but if you dont do that it will also work for negative directed cycles but at very high cost, So we use Bellman and Ford algo for that
    vector<bool> visited(n, false);

    //Dijkstra's algo start here 
    set<pair<int, int>> s;
    int u;
    cout<<"\nEnter the source vertex : ";
    cin>>u;
    s.insert({0, u});
    dist[u] = 0;
    while(!s.empty()){
        auto ele = *(s.begin());
        visited[ele.second] = true;
        s.erase(ele);
        for(auto it : edges[ele.second]){
            if(dist[it[1]] > dist[ele.second] + it[0] && !visited[it[1]]){
                s.erase({dist[it[1]], it[1]});
                dist[it[1]] = dist[ele.second] + it[0];
                s.insert({dist[it[1]], it[1]});
            }
        }
    }
    cout<<"Single source minimum distance of  : ";
    for(int i=0; i<n; i++){
        cout<<"\nVertex "<<i<<" from "<<u<<" is : ";
        if(dist[i] < inf) cout<<dist[i]<<" ";
        else cout<<-1;
    }
    return 0;
}
