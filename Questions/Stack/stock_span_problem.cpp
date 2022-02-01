//Given prices of stock on several days find out from how many previous consecutive days price of stock are less that or equal on that day
//ex :- a[] = {40, 36, 80, 75, 12, 90}
//     ans ={1, 1, 3, 1, 1, 6} 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> stock_span(vector<int> p){
    vector<int> ans;
    stack<pair<int, int> > st;
    for(int i=0; i<p.size(); i++){
        int days = 1;
        while(!st.empty() && st.top().first <= p[i]){
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(p[i], days));
        ans.push_back(days);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        price.push_back(x);
    }

    vector<int> ans = stock_span(price);
    for(int i=0; i<ans.size(); i++ ){
        cout<<ans[i]<<" ";
    }
    return 0;
}