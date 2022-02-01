//Given an array nums, there is a sliding window of size k which is moving from very left of array to very right. You can only see the k numbers at a time. Each sliding window moves right by one position return the max element in sliding window

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void Sliding_window(vector<int> a, int k){
    deque<int> dq;
    int n = a.size();
    vector<int> ans;
    for(int i=0; i<k; i++){
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);
    for(int i=k; i<n; i++){
        if(dq.front() <= i-k) dq.pop_front();

        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
   
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int> a;
    int n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    Sliding_window(a, k);
    return 0;
}