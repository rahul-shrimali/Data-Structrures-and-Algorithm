#include<iostream>

using namespace std;
void merge(int a[], int lb, int mid, int ub){
    int n = mid - lb +1;
    int m = ub - mid;
    int d1[n+1], d2[m+1];
    for(int i=0; i<n; i++){
        d1[i] = a[lb + i];
    }
    for(int i=0; i<m; i++){
        d2[i] = a[mid+i+1];
    }
    d1[n] = __INT_MAX__;
    d2[m] = __INT_MAX__;
    int i=0, j =0;
    for(int k = lb; k<= ub; k++){
        if(d1[i] > d2[j]) {
            a[k] = d2[j];
            j++;
        }
        else{
            a[k] = d1[i];
            i++;
        }
    }
}

void mergeSort(int a[], int lb, int ub){
    if(lb < ub){
        int mid =( lb+ub)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
}

int main(){
    int a[] = {25, 36, 85, 1, -35, 95, 15, 12, -35};
    mergeSort(a, 0, 8);
    for(int i=0; i<9; i++){
        cout<<a[i]<<" ";
    }   
    return 0;
}