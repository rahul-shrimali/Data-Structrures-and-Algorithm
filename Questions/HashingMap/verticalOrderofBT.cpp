//Given a binary tree in array fromat find out the vertical order traversal of that binary tree 
/*
    Sample input :- a[] = {10, 7, 4, 3, 11, 14, 6}
    Sample output = 3 7 10 11 14 4 6
    Explanation - Tree would look like :-       10
                                              /    \
                                             7      4
                                            / \    / \
                                           3   11 14  6 
                In this tree 10 11 14 are in same vertical order
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void VerticalOrder(int a[], int idx, int n, int horizontalLength, 
                    map<int, vector<int>> &mp){
    
    if(idx >= n) return;
    mp[horizontalLength].push_back(a[idx]);
    VerticalOrder(a, 2*idx + 1, n, horizontalLength -1, mp); //Recursively calling for left childs

    VerticalOrder(a, 2*idx + 2, n,  horizontalLength + 1, mp);//REcursively Calling for right childs

}

int main(){
    int a[] = {10, 7, 4, 3, 11, 14, 6};
    map<int, vector<int>> mp;

    VerticalOrder(a, 0, 7, 0, mp);

    map<int, vector<int>> :: iterator itr;

    for(itr = mp.begin(); itr != mp.end(); itr++){
        for(int i = 0; i<(itr->second).size(); i++){
            cout<<(itr->second)[i]<<" ";
        }
    }
    
    return 0;
}