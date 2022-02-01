 //Given an array of height of bars of histogram graph. Find Area of maximum rectangle which can be carved out of that histogram

#include<bits/stdc++.h>
using namespace std;

int get_max_area(int *a, int n){
    int ans =0, i =0;
    stack<int> st;
    while (i<n)
    {
        while(!st.empty() and a[st.top()] > a[i]){
            int t = st.top();
            int h = a[t];
            st.pop();
            if(st.empty()) ans = max(ans, h*i);
            else{
                int len = i-st.top() - 1;
                ans = max(ans, len*h);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    int a[n + 1];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    a[n] = 0;
    int ans = get_max_area(a, n+1);
    cout<<"\n"<<ans;
    return 0;
}