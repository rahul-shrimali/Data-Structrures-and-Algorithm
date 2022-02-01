//Representaion of vector list form
#include<iostream>
#include<vector>
#define rep(i, a, b) for(int i =a; i<b; i++)
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adjL[n+1];
    rep(i, 0, m){
        int x, y;
        cin>>x>>y;
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        cout<<i<<" -> ";
        for(int ele : adjL[i])
            cout<<ele<<" ";
        cout<<"\n";
    }
    return 0;
}