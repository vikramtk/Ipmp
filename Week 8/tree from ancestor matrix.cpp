#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* functione(int arr[][6],int mat[],int size,int cur,int included[])
{
    node*newnode=insert(cur);
    int max=-1,pos=-1;
    for(int i=0;i<size;i++)
    {
        if(arr[cur][i]!=1 || cur==i)
        continue;
        
        if(mat[i]>max && included[i]!=1)
        {
            max=mat[i];pos=i;
        }
    }
    
    if(pos==-1){
    if(included[cur]!=1){
        included[cur]=1;
    }
    return newnode;
    }
    
    included[cur]=1;
    newnode->left=functione(arr,mat,size,pos,included);
    
    max=-1;
    pos=-1;
    for(int i=0;i<size;i++)
    {
        if(arr[cur][i]!=1 || cur==i)
        continue;
        
        if(mat[i]>max && included[i]!=1)
        {
            max=mat[i];pos=i;
        }
    }
    
    if(pos==-1){
    if(included[cur]!=1){
        included[cur]=1;
    }
    return newnode;
    }
    included[cur]=1;
    newnode->right=functione(arr,mat,size,pos,included);
    
    return newnode;
    
}

node* construct(int arr[][6],int size)
{
    int mat[size]={0};
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            mat[i]+=arr[i][j];
        }
    }
    
    int cur=0,max=0;
    for(int i=0;i<size;i++)
    if(mat[i]>max)
    {
    max=mat[i];
    cur=i;
    }
    
    int included[size]={0};
    return functione(arr,mat,size,cur,included);
}

int main()
{
    int arr[6][6] = {{ 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 0 }
    };
    
    inorder(construct(arr,6));
    
    preorder(construct(arr,6));
}
