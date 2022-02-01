//Find whether a graph contains a cycle or not using a union disjoint set
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> parent(N);
vector<int> sz(N);

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

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<N; i++){
        make_set(i);
    }    
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        edges.push_back({x, y});
    }
    bool cycle = false;
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int x = find_parent(u);
        int y = find_parent(v);
        if(x == y) {
            cycle  = true;
            break;
        }
        else{
            union_set(u, v);
        }
    }
    if(cycle) cout<<"Cycle present";
    else cout<<"Cycle not present";
    return 0;
}