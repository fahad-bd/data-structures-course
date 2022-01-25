#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left, *right;

    Node();

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node* add_left(Node* root, int val){
    root->left = new Node(val);
    return root->left;
}

Node* add_right(Node* root, int val){
    root->right = new Node(val);
    return root->right;
}

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

void display_inOrder(Node* root){
    if(root==NULL){
        return;
    }
    display_inOrder(root->left);

    cout<<root->data<<" ";

    display_inOrder(root->right);
    
}

void display_preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    display_preOrder(root->left);
    display_preOrder(root->right);
    
}

bool check_BST(Node *root, Node *min=NULL, Node *max=NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool check_in_left = check_BST(root->left, min, root);
    bool check_in_right = check_BST(root->right, root, max);

    return check_in_left && check_in_right;
}

int main()
{
    Node *root = NULL;
    
    int n;
    cout<<"Input number of Node's : ";
    cin>>n;

    cout<<"Enter node value: ";
    int a;
    cin>>a;
    root = insert_at_BST(root,a);

    if(n==2){
        cin>>a;
        add_left(root,a);
    } 
    
    else if(n==3){
        cin>>a;
        add_left(root,a);
       
        cin>>a;
        add_right(root,a);
        
    }

    else if(n>=3){
        cin>>a;
        add_left(root,a);
        
        cin>>a;
        add_right(root,a);
        
    }

    for (int i = 3; i < n; i++)
    {
        cin>>a;
        insert_at_BST(root,a);
    }

    cout<<"in pre order: ";
    display_preOrder(root);
    cout<<endl;
   
    if(check_BST(root, NULL, NULL)){
        cout<<"It is a BST!"<<endl;
    }else{
        cout<<"It's not a BST"<<endl;
    }

    return 0;
}