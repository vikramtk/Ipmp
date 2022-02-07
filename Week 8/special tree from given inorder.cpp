#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* constructtree(int*in,int start,int end)
{
    if(start>end)
    return NULL;
    
    if(start==end)
    return insert(in[start]);
    
    int i,index=start,max=-999;
    for(i=start;i<=end;i++)
    if(in[i]>max){
    max=in[i];
    index=i;}
    
    node* cur=insert(in[index]);
    cur->left=constructtree(in,start,index-1);
    cur->right=constructtree(in,index+1,end);
    
    return cur;
}

int main()
{
    int in[]={1, 5, 10, 40, 30, 15, 28, 20};
    int n=sizeof(in)/sizeof(in[0]);
    
    inorder(constructtree(in,0,n-1));
    preorder(constructtree(in,0,n-1));
}
