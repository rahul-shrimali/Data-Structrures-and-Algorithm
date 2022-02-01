#include<iostream>
using namespace std;

class Node{       //Creating a node for linked list
    public :
        int data;
        Node* next;
        Node(int n){
            data = n;
            next = NULL;
        }
};

//function to add element at last of linked list
void add(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        head->next = n;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

//function to add element at particular index
void add(Node* &head, int index, int val){
    Node* n = new Node(val);
    if(head == NULL){
        add(head, val);
        return;
    }
    if(index == 0){
        Node* temp = head;
        while (temp->next != head)       
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;
        return;
    }
    Node* temp = head;
    int count = 0;
    while(count < index -1 && temp->next != head){
        temp = temp->next;
        count++;
    }
    Node* d = temp->next;
    temp->next = n;
    n->next = d;
}

//function to display linked list
void display(Node* head){
    Node* temp = head;
    do
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp != head);
    cout<<"head"<<endl;
}

//function to remove element from head
void removeHead(Node* &head){
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = head->next;
    head = temp->next;
    delete todelete;
}

//funciton to delete element from linked list
void remove(Node* &head, int index){
    if(index == 0){
        removeHead(head);
        return;
    }
    int count = 0;
    Node* temp = head;
    while(count < index - 1 && temp->next != head){
        count++;
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;

}

int main(){
    Node* head = NULL;
    add(head,0, 2);
    add(head, 3);
    add(head, 5);
    add(head, 6);
    add(head, 0, 1);
    add(head, 3, 4);
    add(head, 6, 7);
    display(head);

    remove(head, 2);
    display(head);
    return 0;
}