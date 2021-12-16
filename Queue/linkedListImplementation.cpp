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

    void display(){
        if(front==NULL) cout<<"Queue is empty."<<endl;
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    Queue q;

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    q.display();
    cout<<endl;

    cout<<q.peek()<<endl;
    q.deQueue();

    cout<<q.peek()<<endl;
    q.deQueue();

    cout<<q.peek()<<endl;
    q.deQueue();

    q.deQueue();
    cout<<q.empty()<<endl;
    return 0;
}