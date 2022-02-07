#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void childrenSum(node*p)
{
    if(p==NULL)
    return;
    
    if(p->left==NULL && p->right==NULL)
    return;
    
    if(p->left==NULL)
    {
        if(p->right->data>p->data)
        p->data=p->right->data;
        
        if(p->right->data<p->data)
        {
            p->right->data=p->data;
            childrenSum(p->right);
        }
    }
    
    if(p->right==NULL)
    {
        if(p->left->data>p->data)
        p->data=p->left->data;
        
        if(p->left->data<p->data)
        {
            p->left->data=p->data;
            childrenSum(p->left);
        }
    }
    
    if(p->right!=NULL && p->left!=NULL)
    {
        childrenSum(p->left);
        childrenSum(p->right);
        int sum=p->left->data+p->right->data;
        if(sum>p->data)
        p->data=sum;
        
        if(sum<p->data)
        {
            p->left->data=p->data-p->right->data;
            childrenSum(p->left);
        }
    }
}

int main()
{
    node*root=insert(50);
    root->left=insert(7);
    root->right=insert(2);
    root->left->left=insert(3);
    root->right->left=insert(1);
    root->left->right=insert(5);
    root->right->right=insert(30);
    
    childrenSum(root);
    inorder(root);
}
