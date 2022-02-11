#include<bits/stdc++.h>
#include "bst.h"
using namespace std;

int lca(BST*root,int n1,int n2)
{
    if(root->data==n1 || root->data==n2)
    {
        if(root->data==n1)
        return n1;
        else
        return n2;
    }
    
    else if(root->data>n1 && root->data<n2 || root->data<n1 && root->data>n2)
    return root->data;
    
    else if(root->data>n2)
    return lca(root->left,n1,n2);
    
    else
    return lca(root->right,n1,n2);
}

int main()
{
    BST b,*root=NULL;
    root=b.insert(root,20);
    b.insert(root,8);
    b.insert(root,22);
    b.insert(root,4);
    b.insert(root,12);
    b.insert(root,10);
    b.insert(root,14);
    
    cout<<lca(root,10,14)<<endl;
    cout<<lca(root,8,14)<<endl;
    cout<<lca(root,10,22);
}
