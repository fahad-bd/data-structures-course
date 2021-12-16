#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string data)
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

    void push(string x){
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

    string top(){
        if(isEmpty()){
            cout<<"No element in stack."<<endl;
            return "";
        }
        return head->data;
    }
};

void revarse(string s){
    Stack st;
    

    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        
        st.push(word);
    }

    while(!st.isEmpty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    
    string str = "Hey, how are you doing?";

    revarse(str);
    cout<<endl;
    
    return 0;
}