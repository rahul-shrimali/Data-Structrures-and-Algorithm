//Given a tree we have to calculate the diameter of the tree, where diameter of a tree is the  max  distance between its leaf nodes 
/*
Let binary tree is :-
                         1
                        / \
                       2    3
                      / \  / \
                     4   5 6  7
    Its diameter is 5
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
        ~Node(){}
};

//Function to find height of tree
int calc_height(Node* root){
    if(root == NULL){
        return 0;
    }

    return max(calc_height(root->left), calc_height(root->right)) + 1;
}


//Function to find diameter with O(n^2) time complexity
int calc_diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int left_height = calc_height(root->left);
    int right_height = calc_height(root->right);
    int curr_diameter = left_height + right_height + 1;

    int left_dia = calc_diameter(root->left);
    int right_dia = calc_diameter(root->right);

    return max(curr_diameter, max(left_dia, right_dia));
}

//Function to find diameter with O(n) time complexity
int optimized_calc_diameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }

    int left_height = 0, right_height = 0;
    int left_dia = optimized_calc_diameter(root->left, &left_height);
    int right_dia = optimized_calc_diameter(root->right, &right_height);
    int curr_dia = left_height + right_height + 1;
    *height = max(left_height, right_height) + 1;

    return max(curr_dia, max(left_dia, right_dia));    
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    int height = 0;
    cout<<"Diameter through less optiized version : "<<calc_diameter(root)<<"\n";
    cout<<"Diameter through more optiized version : "<<optimized_calc_diameter(root, &height)<<"\n";
    return 0;
}