#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> s1;
    public :
    void enqueue(int x){
        s1.push(x);
    }
    void dequeue();
    bool is_empty(){
        if(s1.empty()){
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
    int x = s1.top();
    s1.pop();
    if(s1.empty()) return;

    dequeue();
    s1.push(x);
}

int Queue :: peek(){
    if(is_empty()){
        cout<<"\nQueue is empty\n";
        return -1;
    }
    int x = s1.top();
    s1.pop();
    if(s1.empty()){
        s1.push(x);
        return x;
    }

    int item = peek();
    s1.push(x);
    return item;
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