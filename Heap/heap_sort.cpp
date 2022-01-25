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
    int left = pos * 2;//6
    int right = pos * 2 + 1;//
    int largest = pos;//3

    if (left <= last && arr[left] > arr[largest])
    {
        largest = left;//6
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

    for (int i = 1; i <= size; i++)
    {
        cin>>heap[i];
    }

    for (int i = size / 2; i >= 1; i--)
    {
        heapify(heap, size, i);
    }

    cout<<"\nMax heap: ";

    for (int i = 1; i <= size; i++)
    {
        cout<<heap[i]<<" ";
    }

    for (int i = size; i>=1; i--)   
    {
        int temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;
        heapify(heap, i-1, 1);
    }

    cout<<"\nSorted array: ";
    for (int i = 1; i <= size; i++){
        cout<<heap[i]<<" ";
    }

    printf("\nMaximum: %d\n", heap[size]);

    return 0;
}
