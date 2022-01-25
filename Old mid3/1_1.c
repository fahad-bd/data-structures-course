#include<stdio.h>
int heap[100], count = 0;

void swap(int position, int parent)
{
    int temp = heap[position];
    heap[position] = heap[parent];
    heap[parent] = temp;
}

void reheapUp(int position)
{
    int parent;
    if (position > 1)
    {
        parent = position / 2;
        if (heap[position] > heap[parent])
        {
            swap(position, parent);
            reheapUp(parent);
            return;
        }
    }
}

void insert(int data)
{
    if (count == 100)
    {
        printf("Heap overflow");
        return;
    }
    else
    {
        count++;
        heap[count] = data;
        reheapUp(count);
    }
}

int priorityNumber(int a, int b, int c){
    return (a/1000) + b - c;
}


int main()
{
    int n;
    printf("Enter pasenger number: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Input for %d:\n",i+1);

        int a,b,c;
        
        printf("Mileage: ");
        scanf("%d",&a);
        printf("Years: ");
        scanf("%d",&b);
        printf("Sequence: ");
        scanf("%d",&c);

        int value = priorityNumber(a,b,c);

        insert(value);

    }

     printf("\nHeap: ");
        for(int i=1;i<=count;i++){
            printf("%d ",heap[i]);
        }
        printf("\n");
    return 0;
}