
#include"/Users/local/include/bits/stdc++.h"
using namespace std;

class Node{
    public:
    int Data;
    Node* Next;

    Node(int value){
        Data=value;
        Next=NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);

    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp = head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;

}

void deleteHead(Node* &head){

    if(head==NULL){
        cout<<"No node found"<<endl;
        return;
    }
    Node* toDelete = head;
    head=head->Next;

    delete toDelete;
}

void printLinkList(Node* n){
    while(n!=NULL){
        cout<<n->Data<<endl;
        n=n->Next;
    }
}

int main()
{
    Node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);

    printLinkList(head);
    deleteHead(head);

    if(head!=NULL){
        cout<<"Link list after delete head: "<<endl;
        printLinkList(head);
    }else printLinkList(head);

    return 0;
}
