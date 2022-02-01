//We are given with a sorted array we have to form a balamced tree from that array 
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

Node* BST_from_sorted(int a[], int start, int end){
    if(start > end) return NULL;

    int mid = (start + end )/2;
    Node* root = new Node(a[mid]);

    root->left = BST_from_sorted(a, start, mid-1);
    root->right = BST_from_sorted(a, mid+1, end);

    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* root = BST_from_sorted(arr, 0, 7);
    preorder(root);
    return 0;
}