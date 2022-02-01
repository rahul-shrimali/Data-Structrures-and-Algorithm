//Given an array find the minimum length of subsequence whose elements sum to a value greater than or equal to k
/*
    Sample input :- a[] = {1, 1, 3, 2, 8} k = 12
    sample output :- 3
*/
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int minSize(int a[], int n, int k){
    priority_queue<int , vector<int>> pq;
    for(int i=0; i<n; i++) pq.push(a[i]);

    int sum = 0, count = 0;
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        sum += x; 
        count++;
        if(sum >= k) break;
    }

    if(sum < k) return -1;
    return count;
}

int main(){
    int a[] = {1, 1, 3, 2, 8};
    int k = 12;
    cout<<"min size is : "<<minSize(a, 5, k);
    return 0;
}