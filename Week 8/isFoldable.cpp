#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int isFoldable(node*p,node*q)
{
    if(p==NULL && q==NULL)
    return 1;
    
    else if(p==NULL || q==NULL)
    return 0;
    
    if(sizeof(p)!=sizeof(q))
    return 0;
    
    if(size(p)==1 && size(q)==1)
    return 1;
    
    else
    {
        
        if(p->left!=NULL && q->right==NULL || p->left==NULL && q->right!=NULL)
        return 0;
        
        else if(q->left!=NULL && p->right==NULL || q->left==NULL && p->right!=NULL)
        return 0;
        
        else
        return isFoldable(p->right,q->left) && isFoldable(p->left,q->right);
    }
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->left->right=insert(3);
    root->right=insert(4);
    root->right->left=insert(5);
    
    if(size(root)==1)
    cout<<1;
    
    cout<<isFoldable(root->left,root->right);
}
