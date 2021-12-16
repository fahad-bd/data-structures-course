#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start=0;
    int end=size;

    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

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
    cout<<"What element do you want to search: ";
    int key;
    cin>>key;

    cout<<"Your element is found in position: ";
    cout<<binarySearch(arr,size,key)<<endl;
    return 0;
}