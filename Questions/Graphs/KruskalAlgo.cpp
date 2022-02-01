/*
    Given an undirected and connected graph G(v, e), a spanning tree of graph G is a tree that spans G(i.e. includes every vertex of G) and is a subgraph of G
    The cost of spanning tree is the sum of the weights of all edges in the tree
    Find the minimum cost of a spanning tree
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> parent(N);
vector<int> sz(N);

void make_set(int x){
    parent[x] = x;
    sz[x] = 1;
}

int find_parent(int v){
    if(parent[v] == v) return v;
    return parent[v] = find_parent(parent[v]);
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
} 

int main(){
    for(int i=0; i<N; i++)
        make_set(i);
    int v, e;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w, u, v});
    }
    

    //Kruskal algo starts for finding min spanning tree

    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto i : edges){
        int weight = i[0];
        int u = i[1];
        int v = i[2];
        u = find_parent(u);
        v = find_parent(v);
        if(u == v) continue;
        else{
            cost += weight;
            union_set(u, v);
        }
    }
    cout<<"\n"<<cost;
    return 0;
}