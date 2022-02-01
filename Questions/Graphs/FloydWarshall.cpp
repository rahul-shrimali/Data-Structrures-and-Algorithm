//Given a graph find the shortest distance between any two edges of the graph

#include<bits/stdc++.h>
using namespace std; 

const int INF = 1e7;

int main(){
    int n, m;
    cin>>n>>m;
    int dist_graph[n][n] = {{INF}};
    for(int i =0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        dist_graph[u][v] = w;
        dist_graph[v][u] = w;
    }

    //Floyd Warshall start here

    for(int k =0; k<n; k++){
        for(int j =0; j<n; j++){
            for(int i = 0; i<n; i++){
                if(dist_graph[i][k]  + dist_graph[k][j] < dist_graph[i][j])
                    dist_graph[i][j] = dist_graph[i][k]  + dist_graph[k][j];
            }   
        }
    }


    //min distance is there
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<dist_graph[i][j] << " ";
        }
    }
    
    return 0;
}