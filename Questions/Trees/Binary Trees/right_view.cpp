//Right view means the rightmost element of each level of a tree
/*
Let binary tree is :-
                         1
                        / \
                       2    3
                      / \  / \
                     4   5 6  7
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* left;
    Node* right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
        ~Node(){
            delete(left);
            delete(right);
            cout<<"called";
        }
};

void right_view(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();
            if(i == n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    right_view(root);
    return 0;
}