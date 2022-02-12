#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

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

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    node*c=maketree(arr,0,n-1);
    
    inorder(c);
    cout<<endl;
    preorder(c);
    cout<<endl;
    postorder(c);
}
