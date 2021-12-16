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
};

void insertAtBottom(Stack &stk, int element){
    
    if(stk.isEmpty()){
        stk.push(element);
        return;
    }

    int topElement = stk.top();
    stk.pop();

    insertAtBottom(stk, element);

    stk.push(topElement);
}

void reverse(Stack &stk){
    if(stk.isEmpty()){
        return;
    }

    int temp = stk.top();
    stk.pop();

    reverse(stk);
    insertAtBottom(stk,temp);
}

int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    reverse(stk);
    while(!stk.isEmpty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
    return 0;
}