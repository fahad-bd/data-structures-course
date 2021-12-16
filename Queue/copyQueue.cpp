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
    
    Node* getFornt(){
        return front;
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

    void display(){
        if(front==NULL) {
            cout<<"Queue is empty."<<endl;
            return;
        }
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

void copy(Queue q1, Queue &q2){
    Node* temp = q1.getFornt();
    while(temp!=NULL){
        int data = temp->data;
        q2.enQueue(data);
        temp=temp->next;
    }
}

int main()
{
    Queue q,q1;

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    copy(q,q1);

    cout<<"Q1: ";
    q.display();
    cout<<endl;
    cout<<"Q2: ";
    q1.display();
    cout<<endl;

    return 0;
}