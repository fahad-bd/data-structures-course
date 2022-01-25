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

void display_inOrder(Node *root){
    if(root==NULL){
        return;
    }
    display_inOrder(root->left);

    cout<<root->data<<" ";

    display_inOrder(root->right);
    
}

void delete_internal_node(Node *root){
    if(root==NULL){
        return; 
    }
    if(root->right != NULL){
        root->data = root->right->data;
        root->right = NULL;
        return;
    }
    else if(root->left != NULL){
        root->data = root->left->data;
        root->right = NULL;
        return;
    }
    delete_internal_node(root->left);
    delete_internal_node(root->right);

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
   
    cout<<"In order: ";
    display_inOrder(root);
    cout<<endl;

    delete_internal_node(root);
    cout<<"After delete internal node: ";
    display_inOrder(root);
    return 0;
}