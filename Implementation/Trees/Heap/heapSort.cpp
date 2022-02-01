//Given an array find the sorted array with help of heap Sort
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void heapify(vector<int> &a, int n, int start){
    int maxIdx = start;
    int l = 2*start +1;
    int r = 2*start + 2;

    if(l < n && a[l] > a[maxIdx]) maxIdx = l;
    if(r < n && a[r] > a[maxIdx]) maxIdx = r;

    if(maxIdx != start){
        swap(a[maxIdx], a[start]);
        heapify(a, n, maxIdx);
    }
}

void heapSort(vector<int> &a){
    int n = a.size();

    for(int i = n/2 -1; i>=0; i--){
        heapify(a, n, i);
    }

    for(int i = n-1; i>0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    vector<int> a = {12, 10, 25, 95, 62, 10, 15, 74};
    heapSort(a);
    for(auto ele : a){
        cout<<ele<<" ";
    }
    return 0;
}