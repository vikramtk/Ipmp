#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int findlevel(node* root,int data,int level)
{
    if(root==NULL)
    return 0;
    
    if(root->data==data)
    return level;
    
    int downlevel=findlevel(root->left,data,level+1);
    if(downlevel!=0)
    return downlevel;
    
    downlevel=findlevel(root->right,data,level+1);
    return downlevel;
}
 
int getLevel(node *root, int data)
{
    return findlevel(root, data, 1);
}

void preorder2(node*root,node*p,int h,int *arr)
{
    if(p!=NULL)
    {
        
        if(arr[getLevel(root,p->data)-1]==0){
        arr[getLevel(root,p->data)-1]=p->data;}
        
        preorder2(root,p->left,h,arr);
        preorder2(root,p->right,h,arr);
    }
}

void leftview(node*root)
{
    int h=maxdepth(root);
    int arr[maxdepth(root)]={0};
    preorder2(root,root,h,arr);
    
    for(int i=0;i<h;i++)
    cout<<arr[i]<<endl;
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    root->right->left=insert(30);
    root->right->right=insert(300);
    root->right->left->left=insert(3000);
    
    leftview(root);
}
