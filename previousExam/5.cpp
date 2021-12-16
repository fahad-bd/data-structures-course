/*
bubble sort in descending orders.
*/

#include<iostream>
using namespace std;
int main()
{
    int arrSize;
    cout<<"Enter total input: ";
    cin>>arrSize;
    int arr[arrSize];
    cout<<"Enter the number: ";
    for(int i=0;i<arrSize;i++){
        cin>>arr[i];
    }

    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i; j < arrSize; j++)
        {
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        
    }
    

    cout<<"Descending orders are: ";
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;

    return 0;
}