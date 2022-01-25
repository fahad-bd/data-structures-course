#include<iostream>
using namespace std;


const int N = INT16_MAX;
bool visited[N];


class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node* front;
    Node* back;

    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void enQueue(int x){
        Node* newNode = new Node(x);
        if(front==NULL){
            front=newNode;
            back=newNode;
        }
        back->next=newNode;
        back=newNode;
    }

    void deQueue(){
        if(front==NULL){
            cout<<"Queue underflow."<<endl;
            return;
        }
        Node* toDelete = front;
        front=front->next;
        delete toDelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"No element in Queue."<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        return front==NULL;
    }

    void display(){
        if(front==NULL) cout<<"Queue is empty."<<endl;
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};



int main()
{
    Queue q;

    int n;
    cout<<"Input the number of nodes: ";
    cin>>n;
    int m;
    cout<<"Input the number of edges: ";
    cin>>m;

    int adjacency[n+1][n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjacency[a][b]=1;
        adjacency[b][a]=1;
    }

    for(int i=0;i<N;i++){
        visited[i]=0;
    }
    
    int 
    return 0;
}