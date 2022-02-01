//Given a snake board find ladders and snake find the minimum amount of moves which can be maid to reach 100
#include<bits/stdc++.h>
using namespace std;

int main(){
    int snakes, ladders;
    cin>>ladders;
    map<int, int> lad;
    for(int i= 0;i <ladders; i++){
        int u, v;
        cin>>u>>v;
        lad[u] = v;
    }
    cin>>snakes;
    map<int, int> snak;
    for (int i = 0; i < snakes; i++){
        int u, v;
        cin>>u>>v;
        snak[u] = v;
    }
    bool complete = false;
    vector<bool> visited(101, 0);
    visited[1] = true;
    queue<int> q;
    q.push(1);
    int ans = 0;
    while(!q.empty() and !complete){
        int sz = q.size();
        while (sz--){
            int t = q.front();
            q.pop();
            for(int i = 1; i<7; i++){
                int pos = t+i;
                if(pos == 100){
                    complete = true;
                    break;
                }
                if(pos <= 100 and lad[pos] and !visited[lad[pos]]){
                    visited[lad[pos]] = true;
                    if(lad[pos] == 100){
                        complete = true;
                        break;
                    }  
                    q.push(lad[pos]);
                }
                else if(pos <= 100 and snak[pos] and !visited[snak[pos]]){
                    visited[snak[pos]] = true;
                    if(snak[pos] == 100 ) complete = true;
                    q.push(snak[pos]);
                }
                else if(pos <= 100) {
                    visited[pos] = true;
                    q.push(pos);
                }
            }
        }     
        ans++;
    }
    if(complete) cout<<ans;
    else cout<<"-1";
    return 0;
}