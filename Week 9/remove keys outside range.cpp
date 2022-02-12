#include<bits/stdc++.h>
#include "bst.h"
using namespace std;

void removerange(BST*root,int a,int b,BST*og)
{
    if(root!=NULL)
    {
        removerange(root->left,a,b,og);
        
        removerange(root->right,a,b,og);
        
        if(root->data<a || root->data>b)
        og=deletenode(og,root->data);
    }
}

int main()
{
    BST b,*root=NULL;
    root=b.insert(root,6);
    b.insert(root,-13);
    b.insert(root,-8);
    b.insert(root,14);
    b.insert(root,13);
    b.insert(root,15);
    b.insert(root,7);
    b.insert(root,-15);
    
    int a=-10,c=13;
    b.inorder(root);
    removerange(root,a,c,root);
    b.inorder(root);
}
