#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int large(node*p,int*min,int*max,int*maxsize,int*isbst)
{
    if(p==NULL)
    {
        *isbst=1;
        return 0;
    }
    
    int ls,rs,mi=INT_MAX,lf=0,rf=0;
    
    *max=INT_MIN;
    
    ls=large(p->left,min,max,maxsize,isbst);
    
    if(*isbst==1 && p->data>*max)
    lf=1;
    
    mi=*min;
    
    *min=INT_MAX;
    rs=large(p->right,min,max,maxsize,isbst);
    
    if(*isbst==1 && p->data<*min)
    rf=1;
    
    if(mi<*min)
    *min=mi;
    
    if(p->data<*min)
    *min=p->data;
    
    if(p->data>*max)
    *max=p->data;
    
    if(lf&&rf)
    {
        if(ls+rs+1>*maxsize)
        *maxsize=ls+rs+1;
        return ls+rs+1;
    }
    else
    {
        *isbst=0;
        return 0;
    }
}

int maxSubtree(node*p)
{
    int min=INT_MAX,max=INT_MIN,maxsize=0,isbst=0;
    
    large(p,&min,&max,&maxsize,&isbst);
    
    return maxsize;
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
    
    cout<<maxSubtree(root);
}

/*
  #include<bits/stdc++.h>
#include "trees.h"
using namespace std;

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

int maxSubtree(node*p)
{
    if(p==NULL)
    return 0;
    
    node*ptr=NULL;
    if(isbst(p,ptr))
    return size(p);
    
    else
    return max(maxSubtree(p->left),maxSubtree(p->right));
    
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
    
    cout<<maxSubtree(root);
}
*/
