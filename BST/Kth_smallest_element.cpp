#include<iostream>
#include<stack>
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

int kthSmakkestNode(Node* root, int k){
    stack<Node*> st;
    Node* temp = root;
    int count =0;
    while(1){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()){
                break;
            }
            temp = st.top();
            st.pop();
            count++;

            if(count == k){
                return temp->data;
            }
            temp = temp->right;
        }
    }
    return -1;
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
    int k;
    cout<<"Input k: ";
    cin>>k;
    cout<<"Kth smallest element: ";
    cout<<kthSmakkestNode(root,k)<<endl;
    return 0;
}