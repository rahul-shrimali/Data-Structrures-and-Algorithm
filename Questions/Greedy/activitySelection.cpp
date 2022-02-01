//You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a singe person, assuming that a person can only work on a single activity at a time
/*
    Sample input :- 3
                    10 20
                    12 15
                    20 30
    Sample output :- 2
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int activities(vector<vector <int>> a, int n){
    sort(a.begin(), a.end(), [&](vector<int>  &a, vector<int> &b){
        return a[1] < b[1];
    });
    int count = 1;
    int end = a[0][1];
    for(int i=1; i<n; i++){
        if(a[i][0] > end){
            end = a[i][1];
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        a.push_back({start, end});
    }
    int ans = activities(a, n);
    cout<<"\nTotal activities are : "<<ans;
    return 0;
}