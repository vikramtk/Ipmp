#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int inorder(node *p,node *q)
{
    if(p==NULL && q==NULL)
    return 1;
    
    if(p!=NULL && q==NULL)
    return 0;
    
    if(p==NULL && q!=NULL)
    return 0;
    
    if(size(p)!=size(q) || height(p)!=height(q))
    return 0;
    
    int flag=1;
    
    if(p->data != q->data)
    return 0;
    
    flag=flag & inorder(p->left,q->left) & inorder(p->right,q->right);
    
    return flag;
}

int main()
{
    node *n1,*n2;
    
    n1=insert(1);
    n1->left=insert(2);
    n1->left->left=insert(20);
    n1->left->right=insert(3);
    n1->left->left->left=insert(12);
    n1->right=insert(0);
    
    n2=insert(1);
    n2->left=insert(2);
    n2->left->left=insert(20);
    n2->left->right=insert(3);
    n2->left->left->left=insert(12);
    n2->right=insert(0);
    
    cout<<inorder(n1,n2);
}
