/*
Input : 12 22 22 123 24
Output : 12 123 24
Input : 12 22 22 12
Output : NULL
Input : 12 22 22 123 12
Output: 12 123 12
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
            cout<<"NULL.";
        }

        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void deletElement(int x){
        if(isEmpty()){
            push(x);
        }
        else if(head->data==x){
            pop();
        }else{
            push(x);
        }
    }
};



int main()
{
    Stack s;
    int sSize;
    cout<<"Size: ";
    cin>>sSize;
    for (int i = 0; i < sSize; i++)
    {
        int x;
        printf("%d element: ",i+1);
        cin>>x;
        s.deletElement(x);
    }
    s.display();

    cout<<endl;

    Stack st;
    while (!s.isEmpty())
    {
        int x=s.top();
        st.push(x);
        s.pop();
    }
    
    st.display();
    cout<<endl;
    return 0;
}