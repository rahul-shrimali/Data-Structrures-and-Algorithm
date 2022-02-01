//Given a tree find the preorder, inorder and postorder traversals of the tree

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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
     if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
     if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->left->right = new Node(-1);

    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);

    return 0;
}


/*
    We are taking a tree as example to show all traversals 
    tree made would look like this :-
                     1
                   /   \
                  2     3
                 / \   / \
                4   5 7   8
                   /     / \
                  6     9   0
                         \                       
                         -1
    
    Its preorder would be :- 1 2 4 5 6 3 7 8 9 -1 0
    Its inorder would be :-  4 2 6 5 1 7 3 9 -1 8 0
    Its postorder would be :-4 6 5 2 7 -1 9 0 8 3 1

*/