//Given a binary tree find the size of largest possible binary search tree in this binary tree
/*
    Example :- let tree be :-    1
                                / \
                               5   9
                              / \   \
                             3   6   7
                            / \   \
                           1   4   8
        Size of largest BST is :- 6 
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


int Largest_BST(Node* root, Node* minNode, Node* maxNode, int &ans){
    if(root == NULL) return 0;
    
    int curr = 0;

    curr = Largest_BST(root->left, NULL, root, ans) + Largest_BST(root->right, root, NULL, ans) + 1;

    ans = max(ans, curr);
    
    if(minNode && root->data < minNode->data){
        return 0;
    }

    if(maxNode && root->data > maxNode->data){
        return 0;
    } 
    
    return curr;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left= new Node(3);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(8);
    root->right->left = new Node(7);
    int ans = 0;

    Largest_BST(root, NULL, NULL, ans);

    cout<<ans<<"\n";
    
    return 0;
}