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

Node *findLastRight(Node *root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}

Node* Delete(Node *root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    Node *rNode = root->right;
    Node *lastRightNode = findLastRight(root->left);
    lastRightNode->right = rNode;

    return root->left;
}

Node *deleteNode(Node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return Delete(root);
    }

    Node *temp = root;
    while (root != NULL)
    {
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = Delete(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != NULL && root->right->data == key){
                root->right = Delete(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
    }
    return temp;
}

int main()
{
    int arr[]={9,8,5,3,2,1,4,7,6,14,12,10,11,13};
    Node *root = NULL;
    root = insert_at_BST(root,arr[0]);
    for (int i = 1; i < 14; i++)
    {
        insert_at_BST(root,arr[i]);
    }
    cout<<"In order: ";
    display_inOrder(root);
    cout<<endl;

    cout<<"Input key for delete: ";
    int key;
    cin>>key;

    cout<<"In order after Delete: ";
    root = deleteNode(root,key);
    display_inOrder(root);
    cout<<endl;
    return 0;
}