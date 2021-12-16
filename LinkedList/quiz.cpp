#include<iostream>
using namespace std;
struct dnode{
    public: 
    int data;
    dnode* next;

    dnode();
    dnode(int val){
        data=val;
        next=NULL;
    }
};

void addNodeAtTail(dnode* &head, int val){
    dnode* newNode = new dnode(val);

    if(head==NULL){
        head=newNode;
        return;
    }

    dnode* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
}

void copy(dnode* head, dnode* &head1){
    head1 = head;
    dnode* temp = head;
    while(temp!=NULL){
        int x;
        x=temp->data;
        dnode* newNode = new dnode(x);
        temp=temp->next;
    }
    
}

void printLinkedList(dnode* h){
    while(h!=NULL){
        cout<<h->data;
        h=h->next;
        if(h!=NULL)cout<<"->";
    }
}

int main()
{
    dnode* head=NULL;
    dnode* head1=NULL;

    int n,m;
    cout<<"Enter size of first list: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        int x;
        printf("Enter data for node %d: ",i);
        cin>>x;

        addNodeAtTail(head,x);
    }

    cout<<"Linked List: ";
    printLinkedList(head);
    cout<<endl;

    copy(head,head1);
    cout<<"Copied Linked List: ";
    printLinkedList(head1);
    cout<<endl;



    return 0;
}