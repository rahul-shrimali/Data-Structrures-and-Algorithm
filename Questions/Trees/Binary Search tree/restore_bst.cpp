//We are given a BST with one value swapped we have to restore that binary tree which means we have to reswap that values
/*
    Ex - Let a binary tree would be :-  6
                                       / \
                                      9   7
                                     / \   \
                                    1   5   3
        In this tree 9 and 3 are swapped 
*/

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

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculate_pointers(Node* root, Node** first, Node** last, Node** mid, Node** prev){
    if(root == NULL) return;

    calculate_pointers(root->left, first, last, mid, prev);
    if((*prev) && (*prev)->data > root->data){
        if(*first){
            *last = root;
        }
        else{
            *first = *prev;
            *mid = root;
        }
    }
    
    *prev = root;
    calculate_pointers(root->right, first, last, mid, prev);
}

void restore_BST(Node* root){
    if(root == NULL) return;

    Node* first, *last, *mid, *prev;
    first = NULL;
    last = NULL;
    mid = NULL;
    prev = NULL;
    calculate_pointers(root, &first, &last, &mid, &prev);

    cout<<"\n"<<first->data<<" "<<last->data<<" "<<mid->data<<"\n";

    if(last) swap(&(first->data), &(last->data));
    else swap(&(first->data), &(mid->data));
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->right = new Node(3);

    inorder(root);
    restore_BST(root);
    cout<<"\n";
    inorder(root);
    return 0;
}