//For a given array and an integer k, check if any subarray exists in array such that elements in the subarray form a number divisible by 3
/*
    sample input : a[] = {8, 23, 45, 12, 56, 4}
    Sample output :- True 
*/

#include<iostream>
using namespace std;

bool divisibleBy3(int a[], int n, int k){
    int sum = 0;
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    if(sum % 3 == 0){
        cout<<a[0]<<a[1]<<a[2];
        return true;
    }
    for(int i =k; i<n; i++){
        sum -= a[i-k];
        sum += a[i];
        if(sum % 3 == 0){
            cout<<a[i-2]<<a[i-1]<<a[i];
            return true;
        }
    }
    return false;
}

int main(){
    int a[] = {8, 23, 45, 12, 56, 4};
    int k = 3;
    if(divisibleBy3(a, 6, k)){
        cout<<" is the number present in Subarray";
    }
    else{
        cout<<"Subarray not present";
    }
    return 0;
}
