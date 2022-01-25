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

void printLinkList(Node* n,int arr[]){
    int c=0;
    while(n!=NULL){
       // cout<<n->Data<<endl;
       arr[c]=n->Data;
        n=n->Next;
        c++;
    }
}

int main()
{
    Node* head = NULL;
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n+1];
/*
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);

*/
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insertAtTail(head,a);
    }
    printLinkList(head,arr);

    int temp = arr[n/2];
    arr[n/2]=arr[0];
    arr[0]=temp;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
