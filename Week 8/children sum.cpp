#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int childrenSum(node*p)
{
    if(p==NULL)
    return 1;
    
    if(p->left==NULL&&p->right==NULL)
    return 1;
    
    else
    {
        if(p->left==NULL)
            return (p->data==p->right->data && childrenSum(p->right));
        
        else if(p->right==NULL)
            return (p->data==p->left->data && childrenSum(p->left));
            
        else
            return (p->data==(p->left->data+p->right->data) && childrenSum(p->left) && childrenSum(p->right));
    }
}

int main()
{
    node*root=insert(10);
    root->left=insert(8);
    root->right=insert(2);
    root->right->right=insert(2);
    root->left->left=insert(3);
    root->left->right=insert(5);
    
    cout<<childrenSum(root);
}
