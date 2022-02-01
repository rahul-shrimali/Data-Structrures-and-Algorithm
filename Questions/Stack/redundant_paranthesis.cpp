//Given an mathematical equation consisting + - * /. Find whether it contains redundant parenthesis or not. Redundant means extra which are not needed
//Ex :- (a+b + (c) ) this is true as it contains one extra parenthesis
// while (a+b+c) is false

#include<bits/stdc++.h>
using namespace std;

bool redundant(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '('){
                return true;
            }
            while(st.top() != '('){
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}

int main(){
    string s;
    getline(cin, s);

    cout<<redundant(s);
    return 0;
}