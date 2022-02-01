//You are given n files and there computation time you have to choose files optimally so that to get the least possible computation time --. Computation time is calculated like :- a[] = "5, 7, 8, 9" then first take any two files and add their computation time and append it to list of times that is a untill a has only one element
/*
    Sample input :- a[] ={5, 2, 4, 7}
    output - 35
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int optimalMerge(vector<int> a, int n){
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int i=0; i<n; i++){
        minHeap.push(a[i]);
    }
    int ans = 0;
    while(minHeap.size() > 1){
        int num1 = minHeap.top();
        minHeap.pop();
        int num2 = minHeap.top();
        minHeap.pop();
        ans += num1 + num2;
        minHeap.push(num1 + num2);
    }
    return ans;
}

int main(){
    vector<int> a = {5, 2, 4, 7};
    cout<<"Minimum time : "<<optimalMerge(a, 4);
    return 0;
}