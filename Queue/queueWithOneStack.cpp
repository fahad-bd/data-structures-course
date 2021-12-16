#include<iostream>
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
};

class Queue{
    Stack s1;

    public:
    void enQueue(int x){
        s1.push(x);
    }
    
    int deQueue(){
        if(s1.isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int x = s1.top();
        s1.pop();

        if(s1.isEmpty()){
            return x;
        }

        int i = deQueue();
        s1.push(x);

        return i;
    }

    bool empty(){
        if(s1.isEmpty()){
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;

    cout<<q.empty()<<endl;

    return 0;
}