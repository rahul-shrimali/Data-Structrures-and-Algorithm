//Given an array of heigth of buildings. find the amount of water that can be trapped in that city
#include<iostream>
using namespace std;
int water(int* a, int n){
    int sum =0;
    int left[n], right[n];
    left[0] = a[0];
    right[n-1] = a[n-1];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], a[i]);
        // cout<<" "<<a[i]<<" ";
    }
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1], a[i]);
    }

    for(int i=0; i<n; i++){
        sum += min(left[i], right[i]) - a[i];
    }
    // cout<<"value";
    return sum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // cout<<"Fun called  ";
    int ans = water(a, n);
    cout<<"\n"<<ans;
    return 0;
}