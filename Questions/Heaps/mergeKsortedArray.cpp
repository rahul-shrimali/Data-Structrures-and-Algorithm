//Given k sorted arrays merge them into a single sorted array
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void merge(vector<vector<int>> a, vector<int> &ans, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> idx(k, 0);
    for(int i=0; i<k; i++){
        minHeap.push({a[i][0], i});
    }

   
    while(!minHeap.empty()){
        pair<int, int> toInsert = minHeap.top();
        minHeap.pop();
        ans.push_back(toInsert.first);
        if(idx[toInsert.second] + 1 < a[toInsert.second].size()){
            minHeap.push({a[toInsert.second][++idx[toInsert.second]], toInsert.second});
        }
    }
}

int main(){
    vector<vector<int>> a = {{1, 4, 6}, {2, 3}, {5, 6, 7}};
    vector<int> ans;
    merge(a, ans, 3);
    for(auto ele : ans){
        cout<<ele<<" ";
    }
    return 0;
}