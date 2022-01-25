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

int countNode(Node* root){
    if(root == NULL) return 0;
    return countNode(root->left) + countNode(root->right) + 1;
}


int main()
{
    Node *root = NULL;

    root = insert_at_BST(root,30);
    insert_at_BST(root,20);
    insert_at_BST(root,40);
    insert_at_BST(root,70);
    insert_at_BST(root,60);
    insert_at_BST(root,80);

    cout<<"In order: ";
    display_inOrder(root);
    cout<<endl;

    cout<<"Total node: "<<countNode(root)<<endl;


    return 0;
}