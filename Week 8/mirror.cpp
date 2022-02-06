#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void mirror(node*p)
{
    if(p==NULL)
    return;
    
    if(size(p)==1)
    return;
    
    node*temp=p->left;
    p->left=p->right;
    p->right=temp;
    
    mirror(p->left);
    mirror(p->right);
}

int main()
{
    node*root=insert(1);
    root->left=insert(3);
    root->right=insert(2);
    root->right->left=insert(5);
    root->right->right=insert(4);
    
    inorder(root);
    
    mirror(root);
    
    inorder(root);
}
