#include<iostream>
using namespace std;

class Node{
public:
    int Data;
    Node* Previous;
    Node* Next;

    Node(int value){
        Data = value;
        Previous = NULL;
        Next = NULL;
    }
};

void addNodeInEnd(Node* &head, int val){
    Node* newNode = new Node(val);

    if(head==NULL){
        head=newNode;
        return;
    }

    Node* temp = head;

    while(temp->Next!=NULL){
        temp=temp->Next;
    }

    temp->Next=newNode;
    newNode->Previous=temp;

}

void addNodeInHead(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->Next=head;
    head->Previous=newNode;

    head=newNode;
}

void addNodeAtMiddle(Node* &head, int key, int val){
    Node* newNode = new Node(val);
    Node* temp = head;

    while(temp->Data!=key){
        temp=temp->Next;
    }
    newNode->Next=temp->Next;
    temp->Next->Previous=newNode;
    temp->Next=newNode;
    newNode->Previous=temp;

}

void printLinkList(Node* h){
    while(h!=NULL){
        cout<<h->Data<<"->";
        h=h->Next;
    }
}

int main()
{
    Node* head = NULL;
    addNodeInEnd(head,1);
    addNodeInEnd(head,2);
    addNodeInEnd(head,3);
    addNodeInEnd(head,4);
    addNodeInEnd(head,5);

    cout<<"Data in linked list before add: "<<endl;
    printLinkList(head);
    cout<<endl;

    cout<<"Data in linked list after add: "<<endl;
    addNodeInHead(head,6);
    printLinkList(head);
    cout<<endl;

    cout<<"Data in linked list after add in middle: "<<endl;
    addNodeAtMiddle(head,2,7);
    printLinkList(head);
    cout<<endl;

    return 0;
}

