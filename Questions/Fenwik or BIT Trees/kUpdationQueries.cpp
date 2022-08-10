#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(long long i=a; i<n; i++)
#define ll long long int
#define pb push_back
#define vi vector<long long>
#define pi pair<long long, long long>
const int mod = 1e9 + 7;

class BIT{
    public:
    vector<ll> tree;
    BIT(int n){
        tree = vector<ll>(n+1, 0);
    }

    void update(ll num, int idx){
        while(idx < tree.size()){
            tree[idx] += num;
            idx += idx & (-idx);
        }
    }

    ll get(ll idx){
        ll sum = 0;
        while(idx){
            sum += tree[idx];
            idx -= idx &(-idx);
        }
        return sum;
    }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin>>n>>m;
	BIT* b = new BIT(n);
	vi a(n);
	rep(i, 0, n) {
		cin>>a[i];
		b->update(a[i], i+1);
	}

	while(m--){
		ll t;
		cin>>t;
		if(t == 1){
			ll idx, val;
			cin>>idx>>val;
			b->update(val - a[idx - 1], idx);
			a[idx - 1] = val;
		}else{
			ll sum;cin>>sum;
			ll s = 1, e = n;
			ll idx = -1;
			while(s <= e){
				ll mid = s + (e-s)/2;
				ll val = b->get(mid);
				if(val < sum ) s = mid + 1;
				else if(val > sum ) e = mid-1;
				else {
					idx = mid;
					break;
				}
			}
			if(idx == -1){
				cout<<"Not Found"<<"\n";
			}else{
				cout<<"Found "<<idx<<"\n";
			}
		}
	}
	return 0;
}
/*
1. Update the position at “x” of array to “y” ie A[x]=y.
2. Find if there is any prefix in the array whose sum equals to “S”.If yes, then output “Found” and the last index of prefix, else output “Not Found”.
As expected, Pheonix123 also did it in about 25 minutes. Now, its challenge for you to do the same.

Note:Array is 1-indexed.

Input
First line contains two space separated integers “N” & “M”, denoting the number of elements in the array and the number of operations or queries.

Second line consists of “N” space separated integers.

Next M lines consists of queries of following form :

1 p q: Change the value at position p to q ie A[p] to q.
(3 space separated numbers)
2 S: Find if there is any prefix whose sum equals “S”.
(2 space separated numbers)
where 1 indicates query of type 1, p is index of array and q is value to be updated with.
Similarly, 2 indicates query of type 2 and S is prefix sum which needs to be checked in the array.

Output
In a single line,for each query of type 2, if the prefix exists in the array,then print a string “Found”(without quotes) along with the index i denoting last position of prefix, separated by space, else print “Not Found”(without quotes).

Constraints
1 ≤ A[i],q ≤ 10^12
1 ≤ N,p ≤ 10^5
1 ≤ M ≤ 10^5
1 ≤ S ≤ 10^17
Example
Input:

4 4
1 2 3 4
2 6
1 4 10
2 16
2 5

Output:

Found 3
Found 4
Not Found
*/