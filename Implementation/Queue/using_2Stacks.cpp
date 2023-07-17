#include<iostream>
#include<stack>
using namespace std;


class Stack{
    public:
    int data;
    Stack* next;
    Stack* top;
    Stack(int d){
        data = d;
        next = NULL;
        top = NULL;
    }

    Stack(){
        top = NULL;
        next = NULL;
    }
    void push(int x){
        if(top == NULL){
            top = new Stack(x);
            return;
        }
        Stack* n = new Stack(x);
        n->next = top;
        top = n;
    }

    bool empty(){
        return top == NULL;
    }

    int get_top(){
        return top->data;
    }

    void pop(){
        top = top->next;
    }
};

class Queue{
    Stack s1, s2;
    public :
    void enqueue(int x){
        s1.push(x);
    }
    void dequeue();
    bool is_empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }    
    int peek();
};

void Queue :: dequeue(){
    if(is_empty()){
        cout<<"\nQueue is empty\n";
        return ;
    }
    if(s2.empty()){
        while(!s1.empty()){
            int x = s1.get_top();
            s2.push(x);
            s1.pop();
        }

    }
    s2.pop();
}

int Queue :: peek(){
    if(is_empty()){
        cout<<"\nQueue is empty\n";
        return -1;
    }
    if(s2.empty()){
        while(!s1.empty()){
            int x = s1.get_top();
            s2.push(x);
            s1.pop();
        }

    }
    int x= s2.get_top();
    return x;
}

int main(){
    Queue q;
    q.enqueue(1);
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

    cout<<"\n"<<q.is_empty();
    return 0;
}