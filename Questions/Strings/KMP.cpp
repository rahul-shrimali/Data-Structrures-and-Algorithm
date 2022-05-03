//Given a string and a pattern find the pattern in the string using kmp algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str, pat;
    int n = 3, m = 3;



    cin>>str>>pat;
    int n = str.length(), m = pat.length();
    vector<int> pi(pat.length(), -1);
    int i = 0, j = 1;
    while(j < m){
        if(pat[j] == pat[i]){
            pi[j] = i;
            i++;
        }else{
            i = 0;
        }
        j++;
    }
    int idx  =-1;
    j = -1;
    for(i =0; i<n; i++){
    //    cout<<i<<" "<<j<<"\n";
       bool here = false;
        if(str[i] == pat[j+1]){
            j++;
            if(j == m - 1){
                idx = i - j;
                break;
            }
        }else{

            while(j != -1 && pat[j+1] != str[i]){
                j = pi[j];
                here = true;
            }
            // i--;
            if(here) i--;
    
        }
    }
    cout<<idx<<" ";
    return 0;
}