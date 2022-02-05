#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* findlca(node*root,int p,int q)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==p || root->data==q)
    return root;
    
    node*l=findlca(root->left,p,q);
    node*r=findlca(root->right,p,q);
    
    if(l!=NULL && r!=NULL)
    return root;
    
    if(l!=NULL)
    return l;
    else return r;
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    root->left->left=insert(20);
    root->right->left=insert(30);
    root->left->right=insert(200);
    root->right->right=insert(300);
    
    cout<<findlca(root,20,200)->data;
}
