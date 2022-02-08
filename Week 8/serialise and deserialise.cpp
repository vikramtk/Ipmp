#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void serialise(node*root,int*arr) //assuming cout to be analogical to fprintf
{
    static int i=0;
    if(root==NULL)
    arr[i++]=-1;
    
    if(root!=NULL)
    {
    arr[i++]=root->data;
    serialise(root->left,arr);
    serialise(root->right,arr);
    }
}

node* deserialise(int arr[],int size)
{
    static int i=0;
    if(arr[i]==-1 || i>=size)
    {i++;
    return NULL;}
    
    node*root=insert(arr[i]);
    i++;
    root->left=deserialise(arr,size);
    root->right=deserialise(arr,size);
    
    return root;
}

int main()
{
    int pos;
    node*root=insert(50);
    root->left=insert(7);
    root->right=insert(2);
    root->left->left=insert(3);
    root->right->left=insert(1);
    root->right->right=insert(30);
    root->right->right->left=insert(4);
    
    int n=size(root);
    int arr[2*n+1];
    
    serialise(root,arr);
    
    for(int i=0;i<2*n+1;i++)
    cout<<arr[i]<<endl;
    
    node*root2=deserialise(arr,2*n+1);
    
    inorder(root2);
}
