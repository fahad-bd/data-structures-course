#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node* front;
    Node* back;

    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void enQueue(int x){
        Node* newNode = new Node(x);
        if(front==NULL){
            front=newNode;
            back=newNode;
        }
        back->next=newNode;
        back=newNode;
    }

    void deQueue(){
        if(front==NULL){
            cout<<"Queue underflow."<<endl;
            return;
        }
        Node* toDelete = front;
        front=front->next;
        delete toDelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"No element in Queue."<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        return front==NULL;
    }
};

class Stack{
    int n;
    Queue q1;
    Queue q2;

    public:
    Stack(){
        n=0;
    }

    void push(int x){
        q2.enQueue(x);
        n++;
        while(!q1.empty()){
            q2.enQueue(q1.peek());
            q1.deQueue();
        }

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.deQueue();
        n--;
    }

    int top(){
        return q1.peek();
    }

    int size(){
        return n;
    }
};

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.top()<<endl;
    return 0;
}