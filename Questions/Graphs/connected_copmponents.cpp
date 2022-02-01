/*
    There are N friends numbered from 0 to N-1. You have to choose 2 person such that they are not related to each other.
    You are  given information in the form of M pairs (x, y) i.e. there is an link between friend x and y.
    Find out yhe number of ways in which 2 persons from different groups can be choosen.

    Based on connected components of graph
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int get_comp(int src, vector<vector<int>> &adj, vector<bool> &visited){
    if(visited[src]) return 0;
    visited[src] = true;
    int ans = 1;
    for(auto it : adj[src]){
        if(!visited[it]) {
            ans += get_comp(it, adj, visited);
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, 0);
    vector<int>component;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            component.push_back(get_comp(i, adj, visited));
        }
    }
    long long int ans = 0;
    for(auto i : component){
        ans += i*(n-i);
    }
    cout<<"Total number of ways = "<<(ans)/2;
    
    return 0;
}