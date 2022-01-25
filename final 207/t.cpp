#include<iostream>
using namespace std;

struct NodeLink{
    public:
    int Data;
    NodeLink* Next;

    NodeLink(int value){
        Data=value;
        Next=NULL;
    }
};

void insertAtTail(NodeLink* &head, int val){
    NodeLink* newNode = new NodeLink(val);

    if(head==NULL){
        head=newNode;
        return;
    }
    NodeLink* temp = head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;

}

void printLinkList(NodeLink* n){
    while(n!=NULL){
        cout<<n->Data<<endl;
        n=n->Next;
    }
}

int main()
{
    NodeLink* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);

    printLinkList(head);

    return 0;
}