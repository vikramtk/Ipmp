#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void assign(node* root,int dist)
{
    if(root!=NULL){
    root->dist=dist;
    
    if(root->left!=NULL)
    assign(root->left,root->dist - 1);
    
    if(root->right!=NULL)
    assign(root->right,root->dist + 1);
    }
}

int post(node *p,int dist)
{
    if(p!=NULL)
    {
        if(p->dist==dist)
        return p->data+post(p->left,dist)+post(p->right,dist);
        else if(p->left==NULL && p->right==NULL)
        {
            if(p->dist==dist)
            return p->data;
            else
            return 0;
        }
        return post(p->left,dist)+post(p->right,dist);
    }
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->left->left=insert(3);
    root->left->right=insert(4);
    root->right=insert(7);
    root->right->left=insert(5);
    root->right->right=insert(6);
    
    assign(root,0);
    
    node*l=root,*r=root;
    
    while(l->left!=NULL)
    l=l->left;
    
    while(r->right!=NULL)
    r=r->right;
    
    int min=l->dist,max=r->dist;
    
    for(int i=min;i<=max;i++)
    {
        cout<<"\nVertical sum of line with distance "<<i<<endl;
        cout<<post(root,i);
    }
}
