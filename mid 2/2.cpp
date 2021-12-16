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

    void Push(int x){
        Node* newNode = new Node(x);
        if(front==NULL){
            front=newNode;
            back=newNode;
        }
        back->next=newNode;
        back=newNode;
    }

    void Pop(){
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
        cout<<endl;
    }
};

int main()
{
    Queue q,qodd,qeven;
/*
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    q.Push(6);
*/
    cout<<"Enter the size of queue: ";
    int size;
    cin>>size;
    cout<<"Input element of queue: ";
    for (int i = 0; i < size; i++)
    {
        int a;
        cin>>a;
        q.Push(a);
        
    }
    

    q.display();

    while(!q.empty())
    {
        int tmp = q.peek();
        if(tmp % 2 == 1) qodd.Push(tmp);
        else qeven.Push(tmp);
        q.Pop();
    }

    while(!qodd.empty())
    {
        q.Push(qodd.peek());
        qodd.Pop();
    }

    while(!qeven.empty())
    {
        q.Push(qeven.peek());
        qeven.Pop();
    }

    q.display();

}