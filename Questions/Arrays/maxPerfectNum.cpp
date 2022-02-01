//For a given array and an integer k, find the maximum perfect numbers in a subarray of size k.
//A perfect number is a number if it is equal to the sum of its preoper divisors except for the number itself
/*
    sample input :- a[] = {28, 2, 3, 6, 496, 99, 8128, 24}, k = 4;
    sample output :- 3
*/
#include<cmath>
#include<iostream>
using namespace std;

bool isPerfect(int n){
    int sum = 1;
    for(int i=2; i<sqrt(n); i++){
        //This is a faster way to find all divisors of a number just in sqrt n time complexity
        if(n%i == 0){
            if(i == n/i) sum += i;
            else sum += i + n/i ;
        }
    }
    if(n != 1 && sum == n) return true;
    return false;
}

int maxPerfect(int a[] , int n, int k){
    for(int i=0; i<n; i++){
        if(isPerfect(a[i])) a[i] = 1;
        else a[i] = 0;
    }

    int sum = 0, result = 0;
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    result = sum;
    for(int i =k; i<n; i++){
        sum += a[i] - a[i-k];
        result = max(result, sum);
    }
    return result;
}

int main(){
    int a[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k  = 4;
    cout<<"Maximum perfect numbers are : "<<maxPerfect(a, 8, k);
    return 0;
}