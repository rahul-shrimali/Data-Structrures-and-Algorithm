//Given a array of size n consisting only 0 and 1's you have to report max consecutive 1's where at most k amount of 0's can also be converted to one's

// Example :- a[] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0} k = 2 Ans = 7
#include<iostream>
using namespace std;

int One(int *a, int n, int k){
    int i=0, ans = 0, zero = 0;
    for(int j=0; j<n; j++){
        if(a[j] == 0) zero++;

        while(zero > k){
            if(a[i] == 0) zero--;
            i++;
        }

        ans = max(ans, j-i+1);
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans = One(a, n, k);
    cout<<"\n"<<ans;
    return 0;
}