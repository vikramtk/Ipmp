#include<bits/stdc++.h>
#include "bst.h"
#include "trees.h"
using namespace std;

int size(BST*p)
{
    if(p==NULL)
    return 0;
    
    else
    return 1+size(p->left)+size(p->right);
}

node* maketree(int*arr,int l,int r)
{
    if(l==r)
    return insert(arr[l]);
    
    if(l==r-1)
    {
        node*p=insert(arr[r]);
        p->left=insert(arr[l]);
        return p;
    }
    
    int mid=(l+r)/2;
    
    node*n=insert(arr[mid]);
    n->left=maketree(arr,l,mid-1);
    n->right=maketree(arr,mid+1,r);
    
    return n;
}

void inorderArr(BST*root,int arr[],int*i)
{
    if(root==NULL)
    return;
    
    if(root!=NULL)
    {
        inorderArr(root->left,arr,i);
        arr[*i]=root->data;
        *i++;
        inorderArr(root->right,arr,i);
    }
}

int* mergeArray(int arr1[],int arr2[],int m,int n)
{
    int *arr=new int[m+n];
    int i=0,j=0,k=0;
    
    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k++]=arr1[i++];
        }
        
        else
        arr[k++]=arr2[j++];
    }
    
    while(i<m)
    arr[k++]=arr1[i++];
    
    while(j<n)
    arr[k++]=arr2[j++];
    
    return arr;
}

void merge(BST*root1,BST*root2,int n1,int n2)
{
    int *arr1 =new int[n1];
    int *arr2 =new int[n2];
    int i=0,j=0;
    inorderArr(root1,arr1,&i);
    inorderArr(root2,arr2,&j);
    
    int *arr=mergeArray(arr1,arr2,n1,n2);
    
    inorder(maketree(arr,0,n1+n2-1));
}

int main()
{
    BST a,b,*root1=NULL,*root2=NULL;
    
    root1=a.insert(root1,10);
    a.insert(root1,2);
    a.insert(root1,11);
    a.insert(root1,1);
    a.insert(root1,5);
    a.insert(root1,3);
    a.insert(root1,7);
    a.insert(root1,12);
    
    root2=b.insert(root2,9);
    b.insert(root2,4);
    b.insert(root2,6);
    b.insert(root2,20);
    b.insert(root2,18);
    b.insert(root2,25);
    
    merge(root1,root2,size(root1),size(root2));
}
