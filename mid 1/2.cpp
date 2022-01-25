#include"iostream"
#include<math.h>
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


void deleteHead(Node* &head){
    Node* toDelete = head;
    head=head->Next;
    head->Previous=NULL;

    delete toDelete;
}


void deleteLastNode(Node* &head){
    Node* temp=head;
    while(temp->Next->Next!=NULL){
        temp=temp->Next;
    }
    Node* toDelete = temp->Next;
    temp->Next->Previous=NULL;
    temp->Next=NULL;

    delete toDelete;
}


void deleteMiddleNode(Node* &head, int possition){

    if(possition==1){
        deleteHead(head);
        return;
    }
    Node* temp=head;
    int count=1;
    while(temp!=NULL && count!=possition){
        temp=temp->Next;
        count++;
    }

    if(temp->Next==NULL){
        deleteLastNode(head);
        return;
    }

    temp->Previous->Next=temp->Next;
    temp->Next->Previous=temp->Previous;

    delete temp;

}

void printLinkList(Node* h){
    while(h!=NULL){
        cout<<h->Data;
        h=h->Next;
        if(h!=NULL)cout<<"->";
    }
}

int main()
{
    Node* head = NULL;

    cout<<"Give input the size of list: ";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        printf("Enter data for %d node: ",i);
        int data;
        cin>>data;
        addNodeInEnd(head,data);
    }

    cout<<"Input the value of K: ";
    int k;
    cin>>k;

    int td = ceil(n/k);
    int todelet = n+1-td;

    cout<<"\nBefore delete"<<endl;
    printLinkList(head);

    cout<<"\nData in linked list after delete node : "<<endl;
    deleteMiddleNode(head,todelet);
    printLinkList(head);


    return 0;
}
