#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node *insert_at_BST(Node *root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert_at_BST(root->left,val);
    }
    else{
        root->right = insert_at_BST(root->right,val);
    }

    return root;
}

int ind = 0;

void display_inOrder(int a[],Node *root){
    if(root==NULL){
        return;
    }
    display_inOrder(a,root->left);

    //cout<<root->data<<" ";
    a[ind] = root -> data;
    ind++;

    display_inOrder(a,root->right);

}

int main()
{
     Node *root = NULL;
    int n;
    cout<<"Input number of Node's in BST: ";
    cin>>n;

    cout<<"Enter node value: ";
    int a;
    cin>>a;
    root = insert_at_BST(root,a);

    for (int i = 1; i < n; i++)
    {
        cin>>a;
        insert_at_BST(root,a);
    }
   
    int arr[n];

    display_inOrder(arr,root);
    //cout<<endl;
    cout<<"Input value of k : ";
    int k;
    cin>>k;
    cout<<"Kth largest element: "<<arr[n-k]<<endl;
    
    return 0;
}
