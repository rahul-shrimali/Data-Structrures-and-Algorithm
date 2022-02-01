//Minimum distance between two nodes of a tree
/*
    Example :- for tree    1
                          / \
                         2   3
                        /   / \
                       4   5   8
                          / \
                         7   6

    min distance between 7 and 8 is 3
*/
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
        ~Node(){
            cout<<"\nded";
            delete(left);
            delete(right);
            delete(&data);
        }
};

//Optimized way of finding LCA
Node* optimized_LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left_LCA = optimized_LCA(root->left, n1, n2);
    Node* right_LCA = optimized_LCA(root->right, n1, n2);

    if(left_LCA && right_LCA) return root;

    if(left_LCA) return left_LCA;
    return right_LCA;
}

int dist(Node* root, int val, int dis){
    if(root == NULL ){
        return -1;
    }
    if(root->data == val){
        return dis;
    }

    int left_dis = dist(root->left, val, dis + 1);
    if(left_dis != -1) return left_dis;

    return dist(root->right, val, dis + 1);
}

int distance(Node* root, int n1, int n2){
    Node* lca = optimized_LCA(root, n1, n2);

    int d1 = dist(lca, n1, 0);
    int d2 = dist(lca, n2, 0);

    return d1 + d2;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(6);
    
    cout<<"Distance between 7 and 8 is : "<<distance(root, 4, 6);
    return 0;
}