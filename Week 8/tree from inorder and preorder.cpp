#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* build(int* inorder,int* preorder,int start,int end,unordered_map <int,int> m)
{
    static int index=0;
    
    if(start>end)
    return NULL;
    
    int cur=preorder[index++];
    
    node* newnode=insert(cur);
    
    if(start==end)
    return newnode;
    
    int c=m[cur];
    
    newnode->left=build(inorder,preorder,start,c-1,m);
    newnode->right=build(inorder,preorder,c+1,end,m);
    
    return newnode;
}

node* buildtree(int* inorder,int* preorder,int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    m[inorder[i]]=i;
    
    return build(inorder,preorder,0,n-1,m);
}

int main()
{
    int inorder[6]={4,2,5,1,6,3};
    int preorder[6]={1,2,4,5,3,6};
    int n=sizeof(preorder)/sizeof(preorder[0]);
    node*root2;
    
    preorder2(buildtree(inorder,preorder,n));
}
