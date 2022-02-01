//We are given a tree we have to find the sum at the k-th level in the tree

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

int sum_atk(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int level = 0;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr){
            if(level == k){
                sum += curr->data;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else if (!q.empty()){
            level++;
            q.push(NULL);
        }
    }
    return sum;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    cout<<sum_atk(root, 2);
    return 0;
}