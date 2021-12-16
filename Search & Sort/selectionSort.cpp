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

    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

    cout<<"Sorted list: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}