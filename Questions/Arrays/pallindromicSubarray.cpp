//For a given array and an integer k, check if any subarray of size k exists in the array such that concatenation form a pallindrome
/*
    Sample input :- a[] = {2, 3, 5, 1, 1, 5}, k = 4;
    Sample output :- 5 1 1 5
*/
#include<cmath>
#include<iostream>
using namespace std;

bool isPallidrome(int n){
    int temp = n, num = 0;
    while(temp > 0){
        num = num*10 + temp%10;
        temp /= 10;
    }
    if(n == num) return true;
    return false;
}

int pallindromeSubarray(int a[], int n, int k){
    int number =0;
    for(int i=0; i<k; i++){
        number = number*10 + a[i];
    }
    if(isPallidrome(number)){
        return 0;
    }
    for(int i=k; i<n; i++){
        number = (number % (int)(pow(10, k-1)) )*10 + a[i];
        if(isPallidrome(number)) return i-k+1;
    }
    return -1;
}

int main(){
    int a[] = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int i = pallindromeSubarray(a, 6, k);
    for(int j = 0; j<k; j++){
        cout<<a[i + j]<<" ";
    }   
    return 0;
}