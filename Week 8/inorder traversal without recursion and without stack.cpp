#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void inorder2(node* root)
{
    node* cur=root;
    
    if(cur==NULL)
    return;
    
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            cout<<cur->data<<endl;
            cur=cur->right;
        }
        
        else
        {
            node*p=cur->left;
            
            while(p->right!=NULL && p->right!=cur)
            p=p->right;
            
            if(p->right==NULL)
            {
                p->right=cur;
                cur=cur->left;
            }
            
            else
            {
                p->right=NULL;
                cout<<cur->data<<endl;
                cur=cur->right;
            }
        }
    }
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    root->left->left=insert(4);
    root->right->right=insert(5);
    root->left->right=insert(6);
    root->right->right->left=insert(7);
    
    inorder2(root);
}
