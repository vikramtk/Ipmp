#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int findmax(node*p)
{
    if(p==NULL)
    return INT_MIN;
    
    return max({p->data,findmax(p->left),findmax(p->right)});
}

int main()
{
    node*root=insert(4);
    root->left=insert(2);
    root->right=insert(1);
    root->left->left=insert(-1);
    root->left->right=insert(2);
    root->right->left=insert(-2);
    root->right->right=insert(3);
    root->left->left->left=insert(-4);
    root->left->left->right=insert(3);
    root->left->right->left=insert(-5);
    root->left->right->right=insert(7);
    
    cout<<findmax(root);
}
