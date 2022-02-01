//Given an unsorted array a of size n of non-negative integers, find a continuous subarray which adds to a given number S
//Input - n= 5, S = 12
//        a[] = {1, 2, 3, 7, 5}
// Output - 2 4

#include<iostream>
using namespace std;

void Sum_Subarr(int* a, int n, int S){
    int i=0, j=0, sum =0;
    while(j<n && sum+a[j] <= S){
        sum += a[j];
        j++;
    }
    if(S == sum){
        cout<<"1 "<<j+1;
        return;
    }
    while(j<n){
        sum += a[j];
        while(S < sum){
            sum -= a[i];
            i++;
        }
        if(sum == S){
            cout<<i+1<<" "<<j+1;
            return;
        }
    }
}

int main(){
    int n, S;
    cin>>n>>S;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    Sum_Subarr(a, n, S);

   
    return 0;
}