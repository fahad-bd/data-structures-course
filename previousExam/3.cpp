/*
stack are equle or not
*/

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
    

public:
    int size;
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

int main()
{
    Stack S1,S2;
    S1.push(5);
    S1.push(10);
    S1.push(15);
    S1.push(50);

    S2.push(5);
    S2.push(10);
    S2.push(15);
    S2.push(50);

    int temp=0;
    int n=S1.size;
    int m=S2.size;

    if(n!=m){
        temp=1;
    }else{
        while (n!=0)
        {
        int k,l;
        k=S1.top();
        l=S2.top();
        if(k!=l){
            temp=1;
            break;
        }
        n--;
        S1.pop();
        S2.pop();
        }
    }
    if(temp==0){
        cout<<"Identical\n";
    }else{
        cout<<"Not Identical\n";
    }
      
    return 0;
}