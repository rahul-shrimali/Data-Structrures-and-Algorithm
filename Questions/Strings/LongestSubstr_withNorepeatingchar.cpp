//Given a string find the length of longest sub string with no repeating character

#include<bits/stdc++.h>
using namespace std;

int longest(string s){
    int start = 0, ans = 0;
    vector<int> ascii(256, -1);  //making vector of 256 length and initializing it with -1
    for(int i=0; i<s.length(); i++){
        if(start < ascii[s[i]]) start = ascii[s[i]];

        ascii[s[i]] = i;
        ans = max(ans, i-start);
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int ans = longest(s);
    cout<<"\n"<<ans;
    return 0;
}