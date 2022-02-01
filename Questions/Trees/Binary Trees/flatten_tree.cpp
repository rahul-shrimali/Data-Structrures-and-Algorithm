//Given a binary tree, flatten it into a linked list inplace. After flattening, left of each node should point to null and right should contain next node in preorder sequence  (Not allowed to use any other data structure)
/*
    let example be :- 1
                     / \ 
                    2   5
                   / \   \
                  3   4   6
    After flattening it looks like :- 1
                                       \ 
                                        2
                                         \ 
                                          3
                                           \ 
                                            4
                                             \ 
                                              5
                                               \ 
                                                6
        Preorder of both are - 1 2 3 4 5 6
*/

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

void flatten(Node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left){
        flatten(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }
    flatten(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    cout<<"Preorder sequence without flattening is : ";
    preorder(root);
    cout<<"\nPreorder sequence after flattening is : ";
    flatten(root);
    preorder(root);

    return 0;
}