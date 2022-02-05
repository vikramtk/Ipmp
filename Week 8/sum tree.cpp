#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int inorder2(node* p)
{
    if(p==NULL || p->left==NULL && p->right==NULL)
    return 1;
    
    if(p->left!=NULL || p->right!=NULL)
    {
        if(p->sum==p->data)
        return inorder2(p->left) && inorder2(p->right);
        
        else return 0;
    }
}

void fun(node* root)
{
    if(root==NULL || root->left==NULL && root->right==NULL)
    return;
    
    else
    {
        root->sum/=2;
        fun(root->left);
        fun(root->right);
    }
}

int sumtree(node*root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    {
        root->sum=root->data;
        return root->data;
    }
    
    else{
    root->sum=root->data+sumtree(root->left)+sumtree(root->right);
    return root->sum;}
}

int main()
{
    node*root=insert(26);
    root->left=insert(10);
    root->right=insert(3);
    root->right->right=insert(3);
    root->left->left=insert(4);
    root->left->right=insert(6);
    
    sumtree(root);
    fun(root);
    cout<<inorder2(root);
}
