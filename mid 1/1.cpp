#include"iostream"
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

void printLinkList(Node* h){

    cout<<"Data entered in the list : "<<endl;

    while(h!=NULL){
        cout<<h->Data<<"->";
        h=h->Next;
    }

}

int check(Node* head, int p){
    Node* temp = head;
    int no=1;
    while(temp!=NULL){
        no++;
        temp=temp->Next;
    }
    if(no<=p) return 1;

    return 0;

}

void Swap(Node* &head, int p){

   Node* temp = head;
   int n=1;
   while(temp!=NULL){
    n++;
    temp=temp->Next;
    if(n==p-1)break;
   }
   Node* k = temp->Next->Next->Next;
   temp->Next->Next->Next=temp->Next;
   temp->Next=k;

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

    int p;
    cout<<"Enter the value of P: "<<endl;
    cin>>p;

    printLinkList(head);

    if(check==0){
        cout<<"Invalid position"<<endl;
    }else{
        Swap(head,p);
        cout<<"List after swap: ";
        printLinkList(head);

    }
    return 0;
}