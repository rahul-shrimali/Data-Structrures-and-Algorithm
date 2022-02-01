//We will form a BST from a given array
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

Node* create_BST(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val< root->data) root->left = create_BST(root->left, val);
    else root->right = create_BST(root->right, val);

    return root;
}

//Function to search value in bst
bool Search_bst(Node* root, int key){
    if(root == NULL) return false;

    if(root->data == key) return true;

    if(key< root->data) return Search_bst(root->left, key);

    return Search_bst(root->right, key);
}

//Function to delete Node from a bst
Node* inorderSucc(Node* root){
    if(root == NULL) return NULL;

    Node* curr = root;
    while(curr && curr->left){
        curr = curr->left;
    }
    return curr;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else{
            Node* n = inorderSucc(root->right);
            root->data = n->data;
            root->right = deleteNode(root->right, n->data);
        }
    }
    return root;
}

//Function to check whether a tree is BST or not
bool isValid(Node* root, Node* min, Node* max){
    if(root == NULL) return true;

    if(min && root->data < min->data) return false;
    if(max && root->data > max->data) return false;

    return isValid(root->left, min, root) and isValid(root->right, root, max);
}
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int a[] = {5, 1, 2, 7, 4, 6, 8, 3};
    Node* root = NULL;
    root = create_BST(root, a[0]);
    for(int i=1; i<sizeof(a)/sizeof(a[0]); i++){
        create_BST(root, a[i]);
    }

    inorder(root);

    if(Search_bst(root, 4)) cout<<"\n4 found in bst";
    else cout<<"\n4 not found in bst";

    deleteNode(root, 3);
    cout<<"\nInorder after removing 3 : ";
    inorder(root);

    deleteNode(root, 4);
    cout<<"\nInorder after removing 4 : ";
    inorder(root);

    deleteNode(root, 7);
    cout<<"\nInorder after removing 7 : ";
    inorder(root);

    if(Search_bst(root, 7)) cout<<"\n7 present in tree";
    else cout<<"\n7 not present in bst";

    if(isValid(root, NULL, NULL)) cout<<"\nTree is valid";
    return 0;
}