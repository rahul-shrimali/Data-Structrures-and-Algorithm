//Given an array of eleemnts and an integer k we have to print the top k elements with maximum frequency in decreasing order
/*
    Sample input :- a[] = {1, 2, 2, 2, 3, 1} k = 2;
    Sample output - 2 1
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void topK(int a[], int n, int k){
    map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }
    vector<pair<int, int>> v;
    map<int, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        v.push_back({it->second, it->first});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int i =0;
    while(i<k){
        cout<<v[i].second<<" ";
        i++;
    }
}

int main(){
    int a[] = {1, 2, 2, 2, 1, 3};
    topK(a, 6, 2);
    return 0;
}