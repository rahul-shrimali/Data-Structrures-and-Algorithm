//LCA = Lowest common ansector is the lowest common node of two nodes 
/*
    Example :- for tree    1
                          / \
                         2   3
                        /   / \
                       4   5   8
                          / \
                         7   6

    LCA of 7 and 8 is :- 3
    Lca of 4 and 8 is :- 1
    Lca of 6 and 7 is :- 5 so on
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

//Less efficient method
bool getPath(Node* root, int key, vector<int>& path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);

    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int less_LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
    
    if(!(getPath(root, n1, path1) && getPath(root, n2, path2))){
        return -1;
    }

    int pc;
    for(pc = 0; pc<path1.size(); pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }
    return path1[pc - 1];
}


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

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(6);

    cout<<"LCA through less efficient method is : "<<less_LCA(root, 7, 8)<<"\n";
    cout<<"LCA through more efficient method is : "<<optimized_LCA(root, 7, 8)->data;
    
    return 0;
}