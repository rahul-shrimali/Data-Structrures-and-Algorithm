//A topological Ordering is an ordering of the nodes in a Directed Acyclic graph where for  wach directed edge from node A to node B, node A appears before node B in the oredering
// topological ordering are not unique. i.e. a graph can have more than one topological ordering
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> in_deg(n, 0);
    for(int i =0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        in_deg[y]++;
    }

    queue<int> pq;
    for(int i=0; i<n; i++){
        if(in_deg[i] == 0) pq.push(i);

    }
    while(!pq.empty()){
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it : adj[x]){
            in_deg[it]--;
            if(in_deg[it] == 0) pq.push(it);
        }
    }
    return 0;
}