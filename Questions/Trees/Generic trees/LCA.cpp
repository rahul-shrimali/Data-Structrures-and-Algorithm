//Find the least common ancestor of two given nodes
#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(long long i=a; i<n; i++)
#define ll long long int
#define pb push_back
#define vi vector<long long>
#define vvi vector<vi> 
#define pi pair<long long, long long>
const int mod = 1e9 + 7;

//method to compute the level of each node
void compute_levels(vvi &adj, ll src, vi &level, ll l){
    level[src]= l;
    for(auto it : adj[src]){
        compute_levels(adj, it, level, l +1);
    }
}

//method to find the lca of two nodes
ll lca(ll first, ll second, vi &level, vvi &ancestors){
    //if both nodes are same then it is lca
    if(first == second) return first;

    if(level[first] > level[second]) swap(first, second);

    //If both nodes are not on same level we make them on same level - used in binary lifting 
    if(level[first] != level[second]){
        ll diff = level[second] - level[first];
        ll anc = log2(diff);
        return lca(first, ancestors[second][anc], level, ancestors);
    }

    // we choose the biggest parent of both nodes which is not same
    for(int i = 11; i>=0; i--){
        if(ancestors[first][i] == -1 || ancestors[second][i] == -1 || ancestors[first][i]==ancestors[second][i]) continue;
        return lca(ancestors[first][i], ancestors[second][i], level, ancestors);
    }

    //if no parent is found the immediate parent is lca
    return ancestors[first][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt = 0;
    ll t; cin>>t; 
    while(t--){
        tt++;
        ll n;  cin>>n; 
        vvi adj(n+1);
        vi in_degree(n+1, 0);
        vvi ancestors(n+1, vi(12, -1));
        rep(i,1,n+1){
            ll sz; cin>>sz;
            rep(j,0,sz){
                ll x; 
                cin>>x;
                in_degree[x]++;
                ancestors[x][0] = i;
                adj[i].pb(x);
            }
        }

        ll root = -1;
        rep(i, 1, n+1){
            if(in_degree[i] == 0){
                root = i;
                break;
            }
        }
        vi level(n+1, 0);
        compute_levels(adj, root, level, 1);

        //computing ancestors
        for(int j = 1; j<12; j++){
            for(int i =1; i<=n; i++){
                ll node = ancestors[i][j-1];
                if(node != -1) ancestors[i][j] = ancestors[node][j-1];
            }
        }
        cout<<"Case "<<tt<<":\n";
        ll q; cin>>q;
        while(q--){
            ll u, v; cin>>u>>v;
            cout<<lca(u, v, level, ancestors)<<"\n";
        }
    }
    return 0;
}

