#include<iostream>

using namespace std;
int partition(int a[], int lb, int ub){
    int s = lb, e = ub, token = a[lb];
    while(s<e){
        while(a[s] <= token){
            s++;
        }
        while (a[e] > token)
        {
            e--;
        }
        if(s < e) swap(a[s], a[e]);
        
    }
    swap(a[lb], a[e]);
    return e;
}
void quickSort(int *a , int lb, int ub){
    if(lb < ub){
        int p = partition(a, lb, ub);
        quickSort(a, p+1, ub);
        quickSort(a, lb, p -1);
    }
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array : \n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    quickSort(a, 0, n-1);
    for (int i = 0; i < 8; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}