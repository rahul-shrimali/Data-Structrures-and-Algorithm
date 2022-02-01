//In this program we will find both total number of nodes and the sum of the nodes of the binary tree
/*
Let binary tree is :-
                         1
                        / \
                       2    3
                      / \  / \
                     4   5 6  7
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

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sum_of_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return sum_of_nodes(root->left) + sum_of_nodes(root->right) + root->data;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    cout<<"Total nodes are : "<<countNodes(root)<<" \n";
    cout<<"Sum of nodes is : "<<sum_of_nodes(root)<<"\n";
    
    return 0;
}