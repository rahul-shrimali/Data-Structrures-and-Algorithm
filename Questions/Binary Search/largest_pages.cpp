//Given an array of n size containing number of pages in n books in ascending order we have to distribute this n books among m students consecutively such that maximum number of pages got by a student are minimum possible 
/*
    Sample input :- arr[] = {1, 2, 5, 7, 11, 12},  m = 2
    Sample output :- 23
    Explanation - When we give books {1, 2, 5, 7} to student 1 and {11, 12} to student 2 then the number of max pages are 23 which is the minimum possible    
*/

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int max){
    int curr_student = 1, sum = arr[0];
    for(int i=1; i<n; i++){
        if(sum + arr[i] > max){
            curr_student++;
            sum = arr[i];
            if(curr_student > m) return false;
        }
        else{
            sum += arr[i];
        }

    }
    return true;
}

int max_pages(int arr[], int n, int m){
    if(n < m) return -1;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int start = 0, end = sum;
    int ans = INT_MAX;
    while(start <= end){
        int max_pages = (start + end)/2;
        if(isPossible(arr, n, m, max_pages)){
            ans = min(ans, max_pages);
            end = max_pages - 1;
        }
        else {
            start = max_pages + 1;
        }
    }

    return ans;

}

int main(){
    int arr[] = {1, 2, 5, 7, 11, 12};
    int m = 2;
    cout<<"Minimum possible Maximum number of pages are : "<<max_pages(arr, 6, m);
    return 0;
}