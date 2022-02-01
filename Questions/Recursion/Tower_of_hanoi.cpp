//Given n disks and three poles you have to move these disk from 1st pole to third such that you can only lift one disk at a time and no bigger disk can be put on smaller disk

#include<iostream>
using namespace std;

void tower_of_hanoi(int n, int from, int to, int aux){
    if(n==1){
        cout<<"\nDisk 1 moved from "<<from<<" to "<<to<<".";
        return;
    }

    tower_of_hanoi(n-1, from, aux, to);
    cout<<"\nDisk "<<n<<" moved from "<<from<<" to "<<to<<".";
    tower_of_hanoi(n-1, aux, to, from);
}

int main(){
    int n;
    cin>>n;

    tower_of_hanoi(n, 1, 3, 2);
    return 0;
}