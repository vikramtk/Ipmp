#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int heightbalanced(node*p)
{
    static bool flag=1;
    
    if(p==NULL)
    return flag;
    
    if(p!=NULL)
    {
        if(abs(maxdepth(p->left)-maxdepth(p->right))>1)
        flag=0;
        
        return flag&&heightbalanced(p->left)&&heightbalanced(p->right);
        
    }
}

int main()
{
    node*root=insert(26);
    root->left=insert(10);
    root->right=insert(3);
    root->right->right=insert(3);
    root->left->left=insert(4);
    root->left->right=insert(6);
    
    cout<<heightbalanced(root);
}
