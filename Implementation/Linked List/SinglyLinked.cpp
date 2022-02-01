//In this we just make a linked list
//This program contains all concepts of linked list.........

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
        ~Node(){}
};
int length(Node* head){
    int l = 0;
    while(head != NULL){
        l++;
        head = head->next;
    }
    return l;
}

void add_last(Node* &head, int val){    //function to add element at last
  
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}

void display(Node* head){   //function to display the linked list
    if(head == NULL) {
        cout<<"linked list empty \n";
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void add_first(Node* &head, int val){    //function to add element at first
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

bool search(Node* head, int key){  //function to search an element from linked list
    while(head != NULL){
        if(head->data == key) return true;

        head = head->next;
    }
    return false;
}

void remove(Node* &head, int key){ //function to remove an element from ll
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        Node* n = head;
        head = NULL;
        delete n;
        return;
    }
    
    if(key == head->data){
        Node* n = head;
        head = head->next;
        delete n;
        return;
    }

    Node* temp = head;
    while(temp->next && temp->next->data != key){
        temp = temp->next;
    }
    if(temp->next == NULL) return;
    Node* n = temp->next;
    temp->next = temp->next->next;
    delete n;
}

void reverse(Node* &head){   //function to reverse linked list 
    Node* pre_ptr = NULL;
    Node* curr_ptr = head;
    Node* next_ptr;
    while(curr_ptr != NULL){
        next_ptr = curr_ptr->next;

        curr_ptr->next = pre_ptr;
        pre_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }
    head = pre_ptr;
}

void add(Node* &head, int index, int val){ //function to add element at particular index
    if(index == 0 && head != NULL){
         add_first(head, val);
         return;
    }

    if(index >= length(head) - 1){
        add_last(head, val);
        return;
    }
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    int i =0;
    Node* temp = head;
    while(i<index - 1){
        temp = temp->next;
        i++;
    }

    Node* demo = temp->next;
    temp->next = n;
    n->next = demo;

}

Node* reverseRecursive(Node* &head){ //function to reverse a ll by recursive moethod
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newnode = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newnode;
}

Node* reverseK(Node* &head, int k){ //Function to reverse k nodes of linked list
    Node* pre_ptr = NULL;
    Node* curr_ptr = head;
    Node* next_ptr;

    int count = 0;
    while(curr_ptr != NULL && count < k){
        next_ptr = curr_ptr->next;
        curr_ptr->next = pre_ptr;
        pre_ptr = curr_ptr;
        curr_ptr = next_ptr;
        count++;
    }

    if(curr_ptr != NULL)
        head->next = reverseK(curr_ptr, k);

    return pre_ptr;
}

void addCycle(Node* head, int index){ //Function to add cycle in linked list
    Node* temp = head;
    int k = 0;
    Node* start;
    while(temp->next != NULL){
        if(k == index){
            start= temp;
        }
        k++;
        temp = temp->next;
    }

    temp->next = start;
}

// Floyd's Algorithm / Hare and tortoise algorithm
bool check_cycle(Node* head){   //Function to check whether there is a cycle in linked list
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// Floyd's Algorithm / Hare and tortoise algorithm
void remove_cycle(Node* head){ //Function to remove cycle from linked list 
    Node* slow = head;
    Node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast);

    //Edge case when both fast and slow coincide on head
    if(fast == head){
        while(fast->next != slow) fast = fast->next;
        fast->next = NULL;
        return;
    }
    
    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}


//Append last k nodes of linked list to top
void appendk(Node* &head, int k){
    int n = length(head);
    k = k%n;
    if(k == 0) return;

    Node* temp = head;
    Node* tail;
    Node* nhead;
    int i =1;
    while(temp->next != NULL){
        if(n-i== k){
            tail = temp;
            nhead = temp->next;
        }
        
        i++;
        temp = temp->next;
    }
    temp->next = head;
    tail->next = NULL;
    head = nhead;

}

//Used to intersect two linked list 
void intersect(Node* head1, Node* head2, int k){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(k>0){
        temp1 = temp1->next;
        k--;
    }
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next  = temp1;
}

//used to find intersection of two linked list
int findIntersection(Node* head1, Node* head2){
    int l1 = length(head1);
    int l2 = length(head2);
    Node* temp1;
    Node* temp2;
    int d;
    if(l1 > l2){
        d = l1 - l2;
        temp1  =head1;
        temp2= head2;
    }
    else{
        d = l2 - l1;
        temp2 = head1;
        temp1 = head2; //Idea is basically bigger ll is temp1
    }
    int ans  =0;
    while(d>0 && temp1 != NULL){
        d--;
        ans++;
        temp1 = temp1->next;
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2) return ans;
        temp1 = temp1->next;
        temp2 = temp2->next;
        ans++; 
    }
    return -1;
}

//Recursive function to merge to sorted linked list in sorted manner
Node* merge(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    Node* result;
    if(head1->data < head2->data){

        result = head1;
        result->next = merge(head1->next, head2); //recursion
    }
    else{
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;
}

//Function to arrange even nodes after odd nodes
void evenAfterOdd(Node* head){
    Node* odd =  head;
    Node* even = head->next;
    Node* evenStart = even;
    while(odd && even and odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenStart;
}

int main(){
    Node* head1 = NULL;
    
    add_last(head1, 1);
    add_last(head1, 2);
    add_last(head1, 3);
    add_last(head1, 4);
    add_last(head1, 5);
    // add_last(head1, 6);
   
    display(head1);
    // display(head2);

    // Node* head  = merge(head1, head2);

    // display(head);
    evenAfterOdd(head1);
    display(head1);
    return 0;
}