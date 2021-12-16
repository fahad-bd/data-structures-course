#include<iostream>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front;
    int back;

    public:
    Queue(){
        arr = new int[n];
        front =-1;
        back=-1;
    }

    void enQueue(int x){
        if(back==n-1){
            cout<<"Queue overflow."<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void deQueue(){
        if(front==-1 || front>back){
            cout<<"No element in Queue."<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"No element in Queue."<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
        return false;
    }
};


int main()
{
    Queue q;

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout<<q.peek()<<endl;
    q.deQueue();

    cout<<q.peek()<<endl;
    q.deQueue();

    cout<<q.peek()<<endl;
    q.deQueue();

    q.deQueue();
    cout<<q.empty()<<endl;
    return 0;
}