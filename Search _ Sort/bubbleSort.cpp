#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"How many data do you want to input: ";
    cin>>size;
    int arr[size];
    cout<<"Input the data: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int count=1;

    while(count<=size){
        for(int i=0;i<size-count;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;
    }

    cout<<"Sorted list: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}