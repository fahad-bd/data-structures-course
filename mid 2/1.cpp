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

    void Push(int x){
        Node* newNode = new Node(x);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void Pop(){
        if(isEmpty()){
            cout<<"No element to pop."<<endl;
            return;
        }
        Node* temp = head;
        head=head->next;

        delete temp;
        size--;
    }

    int Top(){
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
    string s;
    int ind;
    cout<<"string = ";
    cin>>s;
    cout<<"index = ";
    cin>>ind;

    Stack t;

    int ans = -1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '[')
        {
            t.Push(i);
        }
        else if(s[i] == ']')
        {
            int id = t.Top();
            if(id == ind)
            {
                ans = i;
                break;
            }
            t.Pop();
        }
    }

    cout<< ans <<endl;

}
