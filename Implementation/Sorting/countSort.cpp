//Let all the elements of array are positive and maximum element is less than 10
#include<iostream>

using namespace std;

// /*
// BY NET AND TEACHERS
void countSort(int a[], int n){
    
    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[a[i]]++;
    }
    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }
    int dummy[n];
    for(int i = n-1; i>=0; i--){
        dummy[--count[a[i]]] = a[i];
    }
    for(int i=0; i<n; i++){
        a[i] = dummy[i];
    }
}

// */

/*

// BY ME
void countSort(int a[], int n){
    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[a[i]]++;
    }
    int j=0; 
    for(int i=0; i<10; i++){
        while(count[i] > 0){
            a[j] = i;
            j++;
            count[i]--;
        }
    }
}
*/

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array : \n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    countSort(a, n);
    cout<<"Sorted array is : \n";
    for(int i=0; i<n; i++){
        cout<<a[i] <<" ";
    }
    return 0;
}