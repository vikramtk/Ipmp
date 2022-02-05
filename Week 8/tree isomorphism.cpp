#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int isidentical(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)
    return 1;
    
    else if(!(root1!=NULL && root2!=NULL))
    return 0;
    
    else
    {
        if(root1->data!=root2->data)
        return 0;
        
        else
        return isidentical(root1->left,root2->left)&&isidentical(root1->right,root2->right);
    }
}

void sorttree(node*root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL || root->right!=NULL)
        {
            if(root->left==NULL && root->right!=NULL){
            root->left=root->right;
            delete root->right;}
            
            else if(root->left!=NULL && root->right!=NULL)
            {
                if(root->left->data>root->right->data)
                {
                    node*temp=root->left;
                    root->left=root->right;
                    root->right=temp;
                }
                
                sorttree(root->left);
                sorttree(root->right);
            }
        }
    }
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    root->right->left=insert(30);
    root->right->right=insert(300);
    root->right->left->left=insert(3000);
    
    node*root2=insert(1);
    root2->left=insert(3);
    root2->right=insert(2);
    root2->left->left=insert(300);
    root2->left->right=insert(30);
    root2->left->right->left=insert(3000);
    
    sorttree(root);
    sorttree(root2);
    
    cout<<isidentical(root,root2);
}
