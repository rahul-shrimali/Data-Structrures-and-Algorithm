/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive

n =5, k=3, ans = 4
*/

#include<bits/stdc++.h>
using namespace std;

int joseph(int n, int k){
    if(n == 1) return 0;

    return (joseph(n-1, k) + k)%n; 
}

int main(){
    int n, k;
    cin>>n>>k;
    cout<<joseph(n, k);
    return 0;
}