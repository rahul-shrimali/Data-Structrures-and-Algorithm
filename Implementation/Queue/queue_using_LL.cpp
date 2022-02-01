#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
int size(Node* adj){
    Node* temp = adj;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }

    return count;
} 

struct Queue{
    public :
    Node* front = NULL;
    Node* back = NULL;
    void enqueue(int x);
    void dequeue();
    bool empty(){
        if(front == NULL && back == NULL) return true;
        return false;
    }
    int peek();
};

void Queue :: enqueue(int x){
    Node* n = new Node(x);
    // cout<<"in enq";
    if(empty()){
        // cout<<"adding first";
        front = n;
        back = n;
        return;
    }
    back->next = n;
    back = n;
}

void Queue :: dequeue(){
    if(empty()){
        cout<<"\nQueue is empty. \n";
        return;
    }
    if(size(front) == 1) {
        front = NULL;
        back = NULL;
        return;
    }

    Node* todelete = front;
    front = front->next;
    delete todelete;
}

int Queue :: peek(){
    if(empty()){
        cout<<"\nQueue is empty. \n";
        return -1;
    }
    return front->data;
}

int main(){
    Queue q;
    
    q.enqueue(1);
    q.peek();
    q.dequeue();

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.peek()<<" ";
    q.dequeue();

    cout<<q.peek()<<" ";
    q.dequeue();

    cout<<q.peek()<<" ";
    q.dequeue();

    q.enqueue(5);

    cout<<q.peek()<<" ";
    q.dequeue();
    
    cout<<q.peek()<<" ";
    q.dequeue();

    cout<<"\n"<<q.empty();
    return 0;
}