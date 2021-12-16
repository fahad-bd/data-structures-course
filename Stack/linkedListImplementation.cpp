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
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    st.display();
    cout<<endl;

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;

    st.pop();
    st.pop();

    cout<<st.isEmpty()<<endl;
    return 0;
}