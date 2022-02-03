#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void deletetree(node *p)
{
    if(p!=NULL)
    {
        deletetree(p->left);
        deletetree(p->right);
        p->left=p->right=NULL;
        p=NULL;
        free(p);
    }
}

int main()
{
    node *root;
    
    root=insert(0);
    root->left=insert(5);
    root->left->left=insert(4);
    root->left->right=insert(6);
    root->left->left->left=insert(11);
    root->right=insert(20);
    root->right->left=insert(15);
    root->right->right=insert(2);
    
    deletetree(root);
    root=NULL;
    free(root);
    inorder(root);
}
