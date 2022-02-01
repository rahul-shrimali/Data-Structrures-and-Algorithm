#include<bits/stdc++.h>
using namespace std;

int rain_water(int *a, int n){
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() and a[st.top()] < a[i]){
            int curr = st.top();
            st.pop();
            if(st.empty()) break;

            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[curr])*diff;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int ans = rain_water(a, n);
    cout<<"\n"<<ans;
    return 0;
}