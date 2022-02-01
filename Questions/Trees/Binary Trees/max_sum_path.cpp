//Given a binary tree find the maximum sum of any path in the binary tree
/*
    Example -         1
                     / \
                   -8   3
                   /   / \
                  4   5   -6

        Max sum path of this tree has sum of = 9 
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

int calc_max_sum_through_recurs(Node* root, int& ans){
    if(root == NULL) return 0;

    int left_subtree = calc_max_sum_through_recurs(root->left, ans);
    int right_subtree = calc_max_sum_through_recurs(root->right, ans);

    int ans_at_this_subtree = max(max(root->data, left_subtree + right_subtree + root->data), max(left_subtree + root->data, right_subtree + root->data));
    
    ans = max(ans, ans_at_this_subtree);

    int ansector_ans = max(root->data, max(left_subtree + root->data, right_subtree + root->data));

    return ansector_ans;
}

int max_sum_path(Node* root){
    int ans = 0;
    calc_max_sum_through_recurs(root, ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(-8);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    cout<<"Max sum of path is : "<<max_sum_path(root);
    return 0;
}