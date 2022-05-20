// Given an array of integers, and several queries containing a range find the maximum number in the given range

#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &tree, int start, int end, int i, vector<int>&arr){
    if(start == end){
        tree[i] = arr[start];
        return;

    }

    int mid = (start + end)/2;
    buildTree(tree, start, mid, 2*i, arr);
    buildTree(tree, mid + 1, end, 2*i + 1, arr);

    tree[i] = max(tree[2*i], tree[2*i+1]);

}

int findMax(vector<int>&tree, int start, int end, int index, pair<int, int> &query){
    int left = query.first, right = query.second;
    if(left > end || right < start) return INT_MIN;

    if(start == end) return tree[index];

    if(left <= start && end <= right) return tree[index];

    int mid = (start + end)/2;
    int lef = findMax(tree, start, mid, 2*index, query);
    int righ = findMax(tree, mid + 1, end, 2*index + 1, query);

    return max(lef, righ);

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int  i =0; i<n; i++) cin>>arr[i];

    int q;
    cin>>q;
    vector<pair<int, int>> query(q);
    for(int i =0; i<q; i++) cin>>query[i].first>>query[i].second;

    // Main code
    vector<int> tree(4*n);
    buildTree(tree, 0, n-1, 1, arr);

    vector<int> res(q);
    for(int i =0; i<q; i++){
        res[i] = findMax(tree, 0, n-1, 1, query[i]);
    }

    cout<<"\n\n";
    for(int i =0; i<q; i++){
        cout<<res[i]<<"\n";
    }

    return 0;
}