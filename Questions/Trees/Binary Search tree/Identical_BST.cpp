//Given two binary search trees find whether the two are same or not 

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

bool identical(Node* root1, Node* root2){
    if(!root1 && !root2){
        return true;
    }
    if(!root1) return false;
    if(!root2) return false;

    if(root1->data != root2->data) return false;
    
    if(identical(root1->left, root2->left) && identical(root1->right , root2->right)){
        return true;
    }
    return false;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    if(identical(root, root)) cout<<"Trees are identical";
    else cout<<"Trees are not identical";

    if(identical(root, root->left)) cout<<"\nFunction wrong";
    else cout<<"\nFunction right";

    return 0;
}