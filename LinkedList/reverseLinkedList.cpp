#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

void addNode(Node* &head, int value){
    Node* newNode = new Node(value);

    if(head==NULL){
        head=newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
            temp=temp->next;
    }
    temp->next=newNode;
}

Node* reverseLinkList(Node* &head){
    Node* previousNode = NULL;
    Node* currentNode = head;
    Node* nextNode ;

    while(currentNode!=NULL){
        nextNode = currentNode->next;
        currentNode->next=previousNode;

        previousNode=currentNode;
        currentNode=nextNode;
    }
    return previousNode;
}

void printLinkList(Node* h){
    if(h==NULL)cout<<"There is no node in the Linklist\n";
    while(h!=NULL){
        cout<<h->data<<endl;
        h=h->next;
    }
}

int main()
{
    Node* head = NULL;

    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    addNode(head,5);

    cout<<"LinkList before reverse: \n";
    printLinkList(head);

    cout<<"LinkList after reverse: \n";
    Node* newHead = reverseLinkList(head);
    printLinkList(newHead );

    return 0;
}
