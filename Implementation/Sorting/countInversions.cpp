//It uses merge sort
#include<iostream>

using namespace std;
long long merge(int a[], int l, int mid, int e){
    int inv = 0;
    int n1 = mid - l +1;
    int n2 = e - mid;
    int d1[n1], d2[n2];
    for(int i=0; i<n1; i++)
        d1[i] = a[l+i];
    for(int i=0; i<n2; i++)
        d2[i] = a[mid + i + 1];
    int i=0, j=0, k = l;
    while(i<n1 && j < n2){
        if(d1[i] <= d2[j]){
            a[k] = d1[i];
            i++; k++;
        }
        else{
            a[k] = d2[j];
            inv += n1 - i;
            k++; j++;
        }
    }
    while(i<n1){
        a[k] = d1[i];
        i++; k++;
    }
    while(j<n2){
        a[k] = d2[j];
        j++; k++;
    }
    return inv;
}
long long countInversions(int a[], int l, int e){
    long long inv = 0;
    if(l<e){
        int mid = (l+e)/2;
        inv += countInversions(a, l, mid);
        inv += countInversions(a, mid+1, e);
        inv += merge(a, l, mid, e);
    }
    return inv;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    long long inversions = countInversions(a, 0, n-1);
    cout<<inversions;
    return 0;
}