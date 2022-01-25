#include"iostream"
using namespace std;

struct Node{
public:
    int Data;
    Node* Next;

    Node(int value){
        Data=value;
        Next=NULL;
    }
};

void Insert_data(Node* &head, int value){
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

int Isdistinct(Node* head, int val){
    Node* temp = head;
    while(temp!=NULL){
            if(temp->Data==val){
                return 1;
            }
        temp=temp->Next;
    }
    return 0;

}

void printLinkList(Node* h){

    cout<<"Data entered in the list : "<<endl;

    while(h!=NULL){
        cout<<"Data = "<<h->Data<<endl;
        h=h->Next;
    }

}

int main()
{
    struct Node* head = NULL;

    int num=10;

    for(int i=1;i<=num;i++){
        int data;
        printf("Input data for node %d : ",i);
        cin>>data;
        int check;
        check=Isdistinct(head,data);
        if(check==0)
        Insert_data(head,data);
    }

    printLinkList(head);
    return 0;
}