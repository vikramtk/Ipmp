#include<bits/stdc++.h>
using namespace std;

class BST{
    
    public:
    int data;
    BST *left,*right;
            BST(){
                data=0;
                left=right=NULL;
            }
            
            BST(int value){
                data=value;
                left=right=NULL;
            }
            
            BST* insert(BST*,int);
            
            void inorder(BST*);
            void preorder(BST*);
            void postorder(BST*);
            
            BST* deletenode(BST*,int);
};

BST* BST::insert(BST*root,int value)
{
    if(root==NULL)
    return new BST(value);
    
    if(value>root->data)
    root->right=insert(root->right,value);
    
    else
    root->left=insert(root->left,value);
    
    return root;
}

void BST::inorder(BST* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void BST::preorder(BST* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::postorder(BST* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

BST* insuccessor(BST*root)
{
    BST*cur=root->right;
    
    while(cur->left!=NULL)
    cur=cur->left;
    
    return cur;
}

BST* deletenode(BST* root,int data)
{
    if(root==NULL)
    return root;
    
    if(root->data<data)
    root->right=deletenode(root->right,data);
    
    else if(root->data>data)
    root->left=deletenode(root->left,data);
    
    else
    {
        BST*temp;
        
        if(root->left==NULL && root->right==NULL)
        return NULL;
        
        else if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        
        else
        {
            temp=insuccessor(root);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    BST b,*root=NULL;
    root=b.insert(root,5);
    b.insert(root,15);
    b.insert(root,3);
    b.insert(root,7);
    b.insert(root,9);
    b.insert(root,4);
    b.insert(root,1);
    b.insert(root,16);
    
    
    root=deletenode(root,16);
    root=deletenode(root,7);
    root=deletenode(root,5);
    
    b.preorder(root);
    
}
