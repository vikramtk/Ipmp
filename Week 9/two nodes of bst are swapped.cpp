#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void correct(node*p,int*arr)
{
    static int i=0;
    if(p!=NULL)
    {
        correct(p->left,arr);
        
        arr[i++]=p->data;
        
        correct(p->right,arr);
    }
}

void swap(node*root,int a,int b)
{
    if(root!=NULL)
    {
        swap(root->left,a,b);
        
        if(root->data==a)
        root->data=b;
        
        else if(root->data==b)
        root->data=a;
        
        swap(root->right,a,b);
    }
}

int main()
{
    node*root=insert(5);
    root->left=insert(10);
    root->right=insert(20);
    root->left->left=insert(2);
    root->left->right=insert(8);
    
    int n=size(root);
    int arr[n];
    
    correct(root,arr);
    
    int min=99999,max=-99999;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        min=arr[i];
        
        if(arr[i]>max)
        max=arr[i];
    }
    
    int n1=-1,n2=-1;
    
    if(arr[0]!=min)
    n1=arr[0];
    
    if(arr[n-1]!=max)
    n2=arr[n-1];
    
    if(n1==-1 && n2!=-1)
    {
        for(int i=0;i<n-1;i++)
        if(arr[i]>arr[i+1])
        {
            n1=arr[i];
            break;
        }
    }
    
    else if(n1!=-1 && n2==-1)
    {
        for(int i=n-1;i>1;i--)
        if(arr[i]<arr[i-1])
        {
        n2=arr[i];
        break;
        }
    }
    
    else if(n1==-1 && n2==-1)
    {
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]<arr[i-1] || arr[i]>arr[i+1])
            {
                if(n1==-1)
                n1=arr[i];
                else
                n2=arr[i];
            }
        }
    }
    
    swap(root,n1,n2);
    
    inorder(root);
}
