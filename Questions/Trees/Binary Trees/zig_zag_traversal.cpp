//Given a binary tree you have to print the zig zag traversal of that binary tree where zig zag traversal is explained below
/*
    let the binary tree is :-    1
                               /   \
                              2     3
                               \   / \
                                4 8   5
                               / \   / \
                              6   7 9   10
    Then its zigzag traversal first we will print nodes from left to right in a level
    then from right to left in another level and so on 
    like its answer would be :- 1 3 2 4 8 5 10 9 7 6
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zig_zag(stack<Node*> curr, stack<Node*> next, bool l_to_r, vector<int> & ans){
    if(curr.size() == 0) return;
    int n = curr.size();
    for(int i=0; i<n; i++){
        Node* now = curr.top();
        curr.pop();
        ans.push_back(now->data);
        if(l_to_r){
            if(now->left) next.push(now->left);
            if(now->right) next.push(now->right);
        }
        else{
            if(now->right) next.push(now->right);
            if(now->left) next.push(now->left);
        }
    }
    zig_zag(next, curr, !l_to_r, ans);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(5);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    stack<Node*> curr;
    stack<Node*>next;
    vector<int> ans;
    curr.push(root);
    zig_zag(curr, next, true, ans);

    for(auto a : ans){
        cout<<a<<" ";
    }
    return 0;
}