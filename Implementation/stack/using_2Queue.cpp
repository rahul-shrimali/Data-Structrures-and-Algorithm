#include<iostream>
#include<queue>
using namespace std;

class Stack{
    public:
    queue<int> q1, q2;
    void push(int x);
    void pop();
    int top();
    bool is_empty(){
        if(q1.empty()) return true;
        return false;
    }

};

void Stack :: pop(){
    if(q1.empty()) {
        cout<<"stack is empty.\n";
        return ;
    }
    q1.pop();
}

void Stack :: push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

int Stack :: top(){
    if(q1.empty()) {
        cout<<"stack is empty.\n";
        return -1;
    }
    int x = q1.front();
    return x;
}

int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<s.top()<<" ";
    s.pop();

    cout<<s.top()<<" ";
    s.pop();

    cout<<s.top()<<" ";
    s.pop();

    cout<<s.top()<<" ";
    s.pop();

    s.push(7);

    cout<<s.top()<<" ";
    s.pop();

    cout<<s.top()<<" ";
    s.pop();

    cout<<s.top()<<" ";
    s.pop();

    cout<<"\n"<<s.is_empty();
    return 0;
}