#include<iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

void add(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        head->next = NULL;
        head->prev = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp ->next = n;
    n->prev = temp;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void add(Node* &head, int index, int val){
    if(head == NULL) {
        add(head, val);
        return;
    }
    Node* n = new Node(val);
    if(index == 0){
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }

    Node* temp = head;
    int count = 0;
    while(temp != NULL && count < index){
        count++;
        temp = temp->next;
    }

    temp->prev->next = n;
    n->next = temp;
    // if(temp->next != NULL)

}

int main(){
    Node* head = NULL;
    add(head, 1);
    add(head, 2);
    add(head, 4);
    add(head, 2, 3);
    display(head);
    return 0;
}