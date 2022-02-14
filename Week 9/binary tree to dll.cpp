#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* DLL(node* root)
{
    if(root==NULL)
    return root;
    
    if(root->left!=NULL)
    {
        node*left=DLL(root->left);
        
        for(;left->right!=NULL;left=left->right);
        
        left->right=root;
        
        root->left=left;
    }
    
    if(root->right!=NULL)
    {
        node*right=DLL(root->right);
        
        for(;right->left!=NULL;right=right->left);
        
        right->left=root;
        
        root->right=right;
    }
    
    return root;
}

node* makeDLL(node* root)
{
    if(root==NULL)
    return root;
    
    root=DLL(root);
    
    while(root->left!=NULL)
    root=root->left;
    
    return root;
}

int main()
{
    node*root=insert(1);
    root->left=insert(3);
    root->right=insert(2);
    root->left->left=insert(13);
    root->left->right=insert(12);
    root->right->left=insert(30);
    
    node*head=makeDLL(root);
    
    node*cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->right;
    }
}
