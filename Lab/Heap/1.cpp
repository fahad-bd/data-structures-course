#include <iostream>
using namespace std;

void swap(int arr[], int largest, int pos)
{
    int temp = arr[largest];
    arr[largest] = arr[pos];
    arr[pos] = temp;
}

void heapify(int arr[], int last, int pos)
{
    int left = pos * 2;
    int right = pos * 2 + 1;
    int largest = pos;

    if (left <= last && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= last && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != pos)

    {
        swap(arr, largest, pos);
        heapify(arr, last, largest);
    }
}

int main()
{
    printf("Enter the size: ");
    int size;
    cin>>size;

    int heap[size];

    cout<<"Enter element: ";
    for (int i = 1; i <= size; i++)
    {
        cin>>heap[i];
    }

    for (int i = size / 2; i >= 1; i--)
    {
        heapify(heap, size, i);
    }

    for (int i = size; i>=1; i--)   
    {
        int temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;
        heapify(heap, i-1, 1);
    }

    int k;
    cout<<endl;
    cout<<"Enter value of k: ";
    cin>>k;

    int f=0;
    cout<<"\nSorted array: ";
    for (int i = size; i > 0; i--){
        f++;
        cout<<heap[i]<<" ";
        if(f==k)break;
    }
    cout<<endl;
    return 0;
}
