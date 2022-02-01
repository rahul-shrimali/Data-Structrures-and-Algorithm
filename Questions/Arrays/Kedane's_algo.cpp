//This algo give us the max sum of the a continuous sub array
#include<iostream>
using namespace std;

int maxSubArraySum(int *a, int n){
    int max = 0, curr_max = 0;
    for(int i=0; i<n; i++){
        curr_max += a[i];
        if(curr_max > max) max = curr_max;
        if(curr_max < 0) curr_max = 0;
    }

    if(max == 0){
        max = a[0];
        for(int i=1; i<n; i++){
            if(a[i] > max) max = a[i];
        }
    }
    return max;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int ans = maxSubArraySum(a, n);
    cout<<"\n"<<ans;
    return 0;
}