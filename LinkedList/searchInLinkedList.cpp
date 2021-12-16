#include<iostream>
using namespace std;

class Node{
public:
    int Data;
    Node* Next;

    Node(){

    };

    Node(int value){
        Data=value;
        Next=NULL;
    }
};

 void addNodeAtHead(Node* &head, int value){
    Node* newNode = new Node(value);

    newNode->Next=head;
    head=newNode;
 }

 void printLinkList(Node* h){
    while(h!=NULL){
        cout<<h->Data<<endl;
        h=h->Next;
    }
 }

 bool searchInList(Node* h, int key){
    while(h!=NULL){
        if(h->Data==key) return true;
        h=h->Next;
    }
    return false;
 }

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Data=1;
    head->Next=second;

    second->Data=2;
    second->Next=third;

    third->Data=3;
    third->Next=NULL;

    addNodeAtHead(head,4);
    printLinkList(head);

    cout<<searchInList(head,5)<<endl;

    return 0;
}

