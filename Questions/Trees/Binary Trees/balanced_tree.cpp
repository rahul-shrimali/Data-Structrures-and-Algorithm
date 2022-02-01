//A tree is called as balanced tree if the absolute difference between its left heigth and right height is less than or equal to 1
/*
    Let binary tree is :-
                          1
                        /   \
                       2     3
                      / \   / 
                     4   5 6  
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
        ~Node(){}
};

bool is_balanced(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return true;
    }
    int lh =0, rh =0;
    if(!is_balanced(root->left, &lh)){
        return false;
    }
    if(!is_balanced(root->right, &rh)){
        return false;
    }

    *height = max(lh, rh) + 1;

    if(abs(lh-rh) <= 1){
        return true;
    }
    else return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    int height = 0;
    if(is_balanced(root, &height)){
        cout<<"Tree is balanced";
    }
    else cout<<"Tree is not balanced";
    return 0;
}