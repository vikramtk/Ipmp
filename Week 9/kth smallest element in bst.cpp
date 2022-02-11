#include<bits/stdc++.h>
#include "bst.h"
using namespace std;

int size(BST*p)
{
    if(p==NULL)
    return 0;
    
    else
    return 1+size(p->left)+size(p->right);
}

BST* kthSmallest(BST*root,int k)
{
    if(root==NULL)
    return NULL;
    
    if(size(root->left)+1==k)
    return root;
    
    if(size(root->left)+1<k)
    return kthSmallest(root->right,k-size(root->left)-1);
    
    if(size(root->left)+1>k)
    return kthSmallest(root->left,k);
}

int main()
{
    BST b,*root=NULL;
    root=b.insert(root,20);
    b.insert(root,22);
    b.insert(root,8);
    b.insert(root,4);
    b.insert(root,12);
    b.insert(root,10);
    b.insert(root,14);
    
    cout<<kthSmallest(root,5)->data;
}
