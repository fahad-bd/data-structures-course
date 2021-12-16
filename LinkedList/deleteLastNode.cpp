#include<iostream>
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

void addNode(Node* &head, int value){
    Node* newNode = new Node(value);

    if(head==NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=newNode;
}

void deleteLastNode(Node* &head){
    Node* temp = head;
    while(temp->Next->Next!=NULL){
        temp=temp->Next;
    }
    Node* lastNode = temp->Next;
    temp->Next=NULL;
    delete lastNode;
}

void printLinkList(Node* h){

    while(h!=NULL){
        cout<<"Data = "<<h->Data<<endl;
        h=h->Next;
    }

}

int main()
{
    Node* head = NULL;

    int num;
    cout<<"Input the number of nodes : ";
    cin>>num;

    for(int i=1;i<=num;i++){
        int data;
        printf("Input data for node %d : ",i);
        cin>>data;
        addNode(head,data);
    }

    cout<<"Data entered in the list : "<<endl;
    printLinkList(head);

    cout<<"Data in the list after delete last node : "<<endl;
    deleteLastNode(head);
    printLinkList(head);

    return 0;
}

