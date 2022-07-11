/*
Suppose that you have a list of numbers: 1 2 3 4 5-1 1 2 3 4 5 67 8 9 10
2 11 12 -3 1 2 3 4 5. You have to read the numbers without printing them
until a negative number is read. When you find a negative number, then stop
reading and print five items from the list. If there are fewer than five items. then
print an error message and stop the program. Use Queue to solve the problem and
write down an appropriate algorithm and output for this problem.
*/

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

class Queue{
    Node* front;
    Node* back;

    
    public:
    int s;
    Queue(){
        front = NULL;
        back = NULL;
        s=0;
    }
    
    

    void enQueue(int x){
        Node* newNode = new Node(x);
        if(front==NULL){
            front=newNode;
            back=newNode;
        }
        back->next=newNode;
        back=newNode;
        s++;
    }

    void deQueue(){
        if(front==NULL){
            cout<<"Queue underflow."<<endl;
            return;
        }
        Node* toDelete = front;
        front=front->next;
        delete toDelete;
        s--;
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

    while(1){
        int n;
        cin>>n;
        if (n<0)
        {
            break;
        }
        q.enQueue(n);     
    }
    int x=q.s;
    
    if(x<5){
        cout<<"Error!"<<endl;
    }else{
        q.display();
    }
    cout<<endl;

    return 0;
}