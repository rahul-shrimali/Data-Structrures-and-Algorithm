//We are given n items with {value, weight} of each item and capacity of knapsack "w". We need to put these items in knapsack such that final value of items  in knapsack is maximum
/*
    Sample input :- 5
                    21 7
                    24 4
                    12 6
                    40 5
                    30 6
                    20
    Sample output :- 109
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool compare(const pair<int, int> &p1,const pair<int,int> &p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;
    return v1 > v2;
}

int maxValue(vector<pair<int, int>> a, int n, int w){
    sort(a.begin(), a.end(), compare);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(w > a[i].second){
            ans += a[i].first;
            w -= a[i].second;
            continue;
        }
        double v = (double)a[i].first/a[i].second;
        ans += v*w;
        w = 0;
        break;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> a;
    for(int i=0; i<n; i++){
        int val, weight;
        cin>>val>>weight;
        a.push_back({val, weight});
    }
    int w;
    cin>>w;
    int ans = maxValue(a, n, w);
    cout<<"\nMax value can be : "<<ans;
    return 0;
}