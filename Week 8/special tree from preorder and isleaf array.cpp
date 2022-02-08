#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* construct(int*pre,int*isleaf,int x,int *index)
{
    int i=*index;
    
    if(i==x){
    return NULL;
    }
    
    node*p=insert(pre[i]);
    (*index)++;
    
    if(!isleaf[i]){
    p->left=construct(pre,isleaf,x,index);
    p->right=construct(pre,isleaf,x,index);}
    
    return p;
}

node* util(int*pre,int*isleaf,int n)
{
    int index=0;
    return construct(pre,isleaf,n,&index);
}

int main()
{
    int pre[]={10, 30, 5, 15, 20};
    int isleaf[]={0,0,1,0,1};
    int n=sizeof(pre)/sizeof(pre[0]);
    
    node*x=util(pre,isleaf,n);
    
    inorder(x);
}
