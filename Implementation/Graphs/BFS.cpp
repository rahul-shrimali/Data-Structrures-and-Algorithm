//Find the breadth first search of a graph
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5 + 2;
bool visited[N] = {0};
    vector<int> adj[N];
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
   
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        vector<int> :: iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); it++){
            if(!visited[*it]){
                q.push(*it);
                visited[*it] = true;
            }
        }
    }

    return 0;
}
