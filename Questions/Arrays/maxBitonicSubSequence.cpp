//A Bitonic Sub Sequence is a sequence whic is first increasing and then decreasing 

#include<climits>
#include<iostream>
using namespace std;

int maxSumBS(int *a, int n){
    int m = INT_MIN;
    int inc_bs[n];
    int dec_bs[n];
    for(int i=0; i<n; i++){
        inc_bs[i] = a[i];
        dec_bs[i] = a[i];
    }

    //Now computing max increasing sequence
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j] && inc_bs[i] < inc_bs[j] + a[i]){
                inc_bs[i] = inc_bs[j] + a[i];
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(a[i] > a[j] && dec_bs[i] < dec_bs[j] + a[i]){
                dec_bs[i] = dec_bs[j] + a[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        m = max(m, inc_bs[i]+ dec_bs[i] - a[i]);
    }

    return m;


}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans = maxSumBS(a, n);
    cout<<"\n"<<ans;
    return 0;
}