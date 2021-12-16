/*
input: ((A+B)/C Output: Opening parentheses not end
input: (A+B)/C) Output: Closing parentheses not matched
*/

#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char data)
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

    void push(char x){
        Node* newNode = new Node(x);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void pop(){
        if(isEmpty()){
            //cout<<"No element to pop."<<endl;
            return;
        }
        Node* temp = head;
        head=head->next;

        delete temp;
        size--;
    }

    int top(){
        if(isEmpty()){
           // cout<<"No element in stack."<<endl;
            return -1;
        }
        return head->data;
    }
};

void parenthesis(Stack &st, string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
            count++;
        }
        else if(s[i]==')'){
            st.pop();
            count--;
        }
    }
    if(count<0){
        cout<<"Closing parentheses not matched."<<endl;
    }
    else if(count>0){
        cout<<"Opening parentheses not end."<<endl;
    }
    else{
        cout<<"Mathched parenthesis"<<endl;
    }
}

int main()
{
    Stack st;

    cout<<"Input: ";
    string s;
    cin>>s;

    parenthesis(st,s);
    return 0;
}