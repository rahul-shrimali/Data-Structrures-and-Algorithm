//Given a binary tree print all the nodes at a distance k from a target node
/*
    let tree is :-     1
                      / \
                     2   5
                    / \   \
                   3   4   6
                  / \   \
                 7   8   9
        and target is 3 with k 3 then ans is : 9 5
        if target is 2 with k 2 then ans is : 7 8 9 5  
*/

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

void print_Nodes_of_subtree(Node* root, int k){
    if(root == NULL || k < 0) return;
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    print_Nodes_of_subtree(root->left, k-1);
    print_Nodes_of_subtree(root->right, k-1);
}

int Node_at_k(Node* root, Node* target, int k){
    if(root == NULL) return -1;

    if(root == target){
        print_Nodes_of_subtree(root, k);
        return 0;
    }

    int ld = Node_at_k(root->left, target, k);
    if(ld != -1){
        if(ld+1 == k){
            cout<<root->data;
        }
        else{
            print_Nodes_of_subtree(root->right, k - ld - 2);
        }
        return ld + 1;
    }

    int rd = Node_at_k(root->right, target, k);
    if(rd != -1){
        if(rd+1 == k){
            cout<<root->data;
        }
        else{
            print_Nodes_of_subtree(root->left, k - rd - 2);
        }
        return rd + 1;
    }

    return -1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(9);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    
    Node_at_k(root, root->left->left, 3);
    cout<<"\n";
    Node_at_k(root, root->left, 2);
    
    return 0;
}