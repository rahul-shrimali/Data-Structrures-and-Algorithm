/*
    Given an array of Stock Prices of n days. We have to find maximum profit you can earn by buying and selling stocks such that you have to have a cool day after you sell a stock.
    Sample input :- arr = [10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25]
    Sample output :- 19 {series would be b1 s4 c5 b6 s7 c8 b10 s12}
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int obp = -a[0];
    int osp, ocp;
    for(int i =1; i<n; i++){
        int nbp, nsp, ncp;
        if(ocp-a[i] > obp){
            nbp = ocp-a[i];           
        }else{
            nbp = obp;
        }

        if(obp + a[i] > osp){
            nsp = obp + a[i];
        }else{
            nsp = osp;
        }

        if(osp > ocp){
            ncp = osp;
        }else{
            ncp = ocp;
        }

        ocp = ncp;
        obp = nbp;
        osp = nsp;
    }

    cout<<osp;
    return 0;
}