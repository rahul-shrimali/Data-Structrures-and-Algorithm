/*

    If tree is :-        1
                        / \
                       2    3
                      / \  / \
                     4   5 6  7

    then level order traversal is : 1 2 3 4 5 6 7

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
void levelorder(Node* root){
    if(root == NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr){
            cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else if(!q.empty()){
            q.push(NULL);
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
    levelorder(root);
    return 0;
}