#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for Inserting in Left: " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for Inserting in Right: " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelorderTraversal(node *root)
{
    // Separator to separate the level
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp==NULL)
        { // purana level complete ho chuka hai
            cout << endl;
            if (!q.empty())
            { // queue still some children nodes
                q.push(NULL);
            }
        }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }

void inorder(node* root){
    // Base Case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    // Base Case
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    // Base Case
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter the left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right node for: "<<temp->data<<endl;
        int rightData;
        cin>> rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}   

/*
// This Code is used to Count the No. of the leaf Node
void inorder(BinaryTreeNode<int> * root,int &count){
    // Base Case
    if(root==NULL){
        return;
    }
    inorder(root->left,count);
    //leaf Node Condition
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    inorder(root,cnt);
    return cnt;
}
*/

int main()
{
    node* root = NULL;
    //buildFromLevelOrder(root);
    //levelorderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    

    // Creating a Tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //  level order
    cout << "Printing the level order: "<<endl;

    cout<<"Inorder traversal is: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder traversal is: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder traversal is: ";
    postorder(root);
    cout<<endl; 
    

    return 0;
}