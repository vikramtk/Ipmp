#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

struct info{
    int sz,max,min,ans,isbst;
};

bool isbst(node*p,node*&prev)
{
    if(p!=NULL)
    {
        if(!isbst(p->left,prev))
        return 0;
        
        if(prev!=NULL && prev->data>p->data)
        return 0;
        prev=p;
        return isbst(p->right,prev);
    }
    return 1;
}

info large(node* root)
{
   if(root==NULL)
   return {0,INT_MIN,INT_MAX,0,1};
   
   if(root->left==NULL && root->right==NULL)
   return {1,root->data,root->data,1,1};
   
   info l=large(root->left);
   info r=large(root->right);
   
   info e;
   e.sz=l.sz+r.sz+1;
   
   if(l.isbst && r.isbst && l.max<root->data && r.min>root->data)
   {
       e.min=min(l.min,min(r.min,root->data));
       e.max=max(r.max,max(l.max,root->data));
       
       e.ans=e.sz;
       e.isbst=1;
       
       return e;
   }
   
   e.ans=max(l.ans,r.ans);
   e.isbst=0;
   
   return e;
}

int main()
{
    node *root = insert(50);
    root->left = insert(10);
    root->right = insert(60);
    root->left->left = insert(5);
    root->left->right = insert(20);
    root->right->left = insert(55);
    root->right->left->left = insert(45);
    root->right->right = insert(70);
    root->right->right->left = insert(65);
    root->right->right->right = insert(80);
    
    cout<<large(root).ans;
}
