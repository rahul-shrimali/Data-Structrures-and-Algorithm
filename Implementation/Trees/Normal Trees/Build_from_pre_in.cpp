//In this program we are going to build a tree from inorder and preorder
//The concept of postorder and inorder would be same just only idx will start from end and keep on decreasing

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

static int idx = 0;

int search(int inorder[], int start, int end, int key){
    for(int i=start; i<=end; i++){
        if(key == inorder[i]){
            return i;
        }
    }
    return -1;
}

Node* build(int preorder[], int inorder[], int start, int end){
    if(start > end){
        return NULL;
    }
    int key = preorder[idx];
    idx++;
    Node* new_node = new Node(key);
    if(start == end){
        return new_node;
    }

    int srch = search(inorder, start, end, key);
    new_node->left = build(preorder, inorder, start, srch - 1);
    new_node->right = build(preorder, inorder, srch+ 1, end);

    return new_node;
}

void in(Node* root){
    if(root == NULL){
        return;
    }
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}

int main(){
    int preorder[] = {1, 2, 4, 5, 6, 3, 7, 8, 9, -1, 0};
    int inorder[] = {4, 2, 6, 5, 1, 7, 3, 9, -1, 8, 0};
    Node* root = build(preorder, inorder, 0, 10);
    in(root);
    return 0;
}