//We will form a BST from a given array
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

Node* create_BST_preorder(int preorder[], int* preidx, int key, int min, int max, int n){
    if(*preidx >= n) return NULL;

    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preidx = *preidx + 1;

        if(*preidx < n){
            root->left = create_BST_preorder(preorder, preidx, preorder[*preidx], min, key, n);
        }

        if(*preidx < n){
            root->right = create_BST_preorder(preorder, preidx, preorder[*preidx], key, max, n);
        }
    }

    return root;
}


void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int a[] = {10, 5, 7, 6, 40, 50};
    int n = 8;
    Node* root = NULL;
    int preidx = 0;
    root = create_BST_preorder(a, &preidx, a[0], INT_MIN, INT_MAX, n);
    inorder(root);
    return 0;
}