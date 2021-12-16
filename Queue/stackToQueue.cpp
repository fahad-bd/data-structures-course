

//it doesnot work.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    Node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size=0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size ==0;
    }

    Node* getHead(){
        return head;
    }

    void push(int x){
        Node* newNode = new Node(x);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout<<"No element to pop."<<endl;
            return;
        }
        Node* temp = head;
        head=head->next;

        delete temp;
        size--;
    }

    int top(){
        if(isEmpty()){
            cout<<"No element in stack."<<endl;
            return -1;
        }
        return head->data;
    }

    void display(){
        if(head==NULL){
            cout<<"Stack is empty.";
        }

        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

class Queue{
    public:
    
    Stack *s;
    Node* front;
    Node* back;

    Queue(){
        front=NULL;
        back=NULL;
    }

    void enQueue(int x){
        if(s->isEmpty()){
            s->push(x);
            front=s->getHead();
            back=s->getHead();   
        }
        s->push(x);
        Node* temp = s->getHead();
        while(temp!=NULL){
            temp=temp->next;
        }
        back=temp;
    }

    void deQueue(){
        if(s->isEmpty()){
            cout<<"No element in QUeue."<<endl;
            return;
        }
        Node* toDelete=back;
        Node* temp=s->getHead();

        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        back=temp;
        delete toDelete;
    }

    void peek(){
        if(front==NULL){
            cout<<"Queue is empty."<<endl;
        }
        cout<<back->data;
    }

    bool isEmpty(){
        return front==NULL;
    }
};

int main()
{
    Queue* q;

    q->enQueue(1);
    q->enQueue(2);
    q->enQueue(3);
    q->enQueue(4);
    q->enQueue(5);

    q->peek();

    while(q->isEmpty()){
        q->peek();
        cout<<" ";
        q->deQueue();
    }
    return 0;
}