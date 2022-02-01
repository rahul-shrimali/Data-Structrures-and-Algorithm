/*
    A group of cows grabbed a truck and ventured on a expidition deep into the jungle. The truck leaks 1 unit of fuel every unit of distance it travels.
    To repair the truck the cows need to drive to the nearest town. On this road, between the town and truck there are N fuel stops where the cows can stop to aquire additional fuel
    The cows want to make the minimum possible number of stops for fuel on the way to town.
    Capacity of tank is infinity.
    Initial unit of fuel is 'p' and distance of town from truck is 'l'.
    find minimum number stops required

     Sample input :- 
     4
     4 4
     5 2
     11 5
     15 10 
     10 25
    Sample output :- 2
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minStops(vector<pair<int, int>> &a, int n, int p, int l){
    for(int i=0; i<n; i++){
        a[i].first = l - a[i].first;
    }
    sort(a.begin(), a.end());
    
    priority_queue<int, vector<int> > maxHeap;
    int ans = 0;
    int curr = p;
    for(int i=0; i<n; i++){
        if(curr >= l) return ans;
        while(curr < a[i].first){
            if(maxHeap.empty()){
                return -1;
            }
            ans++;
            curr += maxHeap.top();
            maxHeap.pop();
        }
        maxHeap.push(a[i].second);
    }
    while(curr < l){
        if(maxHeap.empty()) return -1;
        curr += maxHeap.top();
        maxHeap.pop();
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i].first>>a[i].second;
    }
    // a.push_back({4, 4});
    // a.push_back({5, 2});
    // a.push_back({11, 5});
    // a.push_back({15, 10});

    int p, l;
    cin>>p>>l;

    // cout<<"y mera nam jh \n";
    cout<<"Minimum stops are : "<<minStops(a, n, p, l);

    return 0;
}