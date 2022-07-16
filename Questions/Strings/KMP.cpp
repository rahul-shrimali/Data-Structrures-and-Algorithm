//Given a string and a pattern find the pattern in the string using kmp algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str, pat;
    cin>>str>>pat;
    int n = str.length(), m = pat.length();
    vector<int> pi(pat.length(), 0);
    int i = 0, j = 1;
    while(j < m){
        if(pat[j] == pat[i]){
            i++;
            pi[j++] = i;
        }else{
            if(i != 0){
                i = pi[i-1];
            }else{
                j++;
            }
        }
    }
    
    int idx  =-1;
    j = 0, i = 0;
    while(i < n){
        if(str[i] == pat[j]){
            i++;
            j++;
            if(j == m) {
                idx = i - m ;
                break;
            }
        }else{
            if(j != 0) j = pi[j-1];
            else i++;
        }
    }
    cout<<idx<<" ";
    return 0;
}