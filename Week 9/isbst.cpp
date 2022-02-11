#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

bool isbst(node*p,node*&prev)
{
    if(p!=NULL)
    {
        if(!isbst(p->left,prev))
        return 0;
        
        if(prev!=NULL && prev->data>p->data)
        return 0;
        prev=p;
        return isbst(p->right,prev);
    }
    return 1;
}

int main()
{
    node*p=insert(7);
    p->left=insert(3);
    p->right=insert(8);
    p->left->left=insert(1);
    p->left->right=insert(4);
    p->left->right->right=insert(6);
    p->right->right=insert(10);
    
    node*arr=NULL;
    cout<<isbst(p,arr);
}
