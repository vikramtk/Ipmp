#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* construct(int pre[],int post[],int *index,int l,int h,int n)
{
    if(*index>=n || l>h)
    return NULL;
    
    node*root=insert(pre[*index]);
    ++(*index);
    
    if(l==h)
    return root;
    
    int i;
    for(i=l;i<=h;i++)
    if(pre[*index]==post[i])
    break;
    
    if(i<=h)
    {
        root->left=construct(pre,post,index,l,i,n);
        root->right=construct(pre,post,index,i+1,h-1,n);
    }
    
    return root;
}

void util(int pre[],int post[],int n)
{
    int index=0;
    inorder(construct(pre,post,&index,0,n-1,n));
}

int main()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof( pre ) / sizeof( pre[0] );
 
    util(pre,post,n);
}
