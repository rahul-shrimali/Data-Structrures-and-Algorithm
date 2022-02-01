//Given a tree replace the daat of each node with the sum of its left and right nodes with the node
/*
Let binary tree is :-
                         1
                        / \
                       2    3
                      / \  / \
                     4   5 6  7
            its inorder = 4 2 5 1 6 3 7
After Sum replacement tree would look like :-
                         28
                        /  \
                       11   16
                      / \   / \
                     4   5  6  7
            its inorder = 4 11 5 28 6 16 7
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void sum_replacement(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }
    sum_replacement(root->left);
    sum_replacement(root->right);
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
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

    cout<<"Inorder without sum replacement : "; 
    inorder(root);
    sum_replacement(root);
    cout<<"\nInorder after sum replacement : "; 
    inorder(root);

    return 0;
}