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
    //cout<<root->data<<" ";
}

Node *search_in_BST(Node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data > key){
        return search_in_BST(root->left, key);
    }
    return search_in_BST(root->right,key);
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

    display_inOrder(root);
    cout<<endl;

    if(search_in_BST(root,70)==NULL){
        cout<<"Not fount in BST.\n";
    }else{
        cout<<"Fount in BST\n";
    }
    return 0;
}