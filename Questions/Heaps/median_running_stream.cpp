//Given an array of size n you have to consider a string in which inputs are elements of array and find the median at that time
/*
    Sample input :- a[] = {10, 15, 21, 30, 18, 19}
    Sample output :- 10 12.5 15 18 18 18.5

    Explanation :- at first string = 10 so median = 10
    then string = 10 15 median = 12.5
    then string = 10 15 21   median = 15
    string = 10 15 21 30     median = 18
    string = 10 15 21 30 18  median is found in sorted arr so string = 10 15 18 21 30
    median = 18
    string = 10 15 18 19 21 30   median = 18.5
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void insert(int n){
    if(minHeap.size() == maxHeap.size()){
        if(maxHeap.size() == 0) maxHeap.push(n);
        else{
            if(n > maxHeap.top()) minHeap.push(n);
            else maxHeap.push(n);
        }
    }
    else if(minHeap.size() < maxHeap.size()){
        if(n > maxHeap.top()) minHeap.push(n);
        else{
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
            maxHeap.push(n);
        }
    }
    else{
        if(n < minHeap.top()) maxHeap.push(n);
        else{
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
            minHeap.push(n);
        }
    }
}

void median_runningStream(vector<int> a){
    int n = a.size();
    for(int i=0; i<n; i++){
        insert(a[i]);
        if(minHeap.size() == maxHeap.size()) cout<<(minHeap.top() + maxHeap.top())/2.0<<" ";
        else if(minHeap.size() < maxHeap.size()) cout<<maxHeap.top()<<" ";
        else cout<<minHeap.top()<<" ";
    }
}

int main(){
    vector<int> a = {10, 15, 21, 30, 18, 19};
    cout<<"Median running stream of this vector input is : ";
    median_runningStream(a);
    return 0;
}