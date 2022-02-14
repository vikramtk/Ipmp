//Note:The flag of nodes still present in tree are made as 1,and those with 0 can be deleted

#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void deleteTree(node* node)
{
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
     
    delete node;
}

int pathLength(node*root)
{
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    return root->data;
    
    return root->data+max(pathLength(root->left),pathLength(root->right));
}

void assignPathLength(node*root,int data)
{
    if(root!=NULL)
    {
        root->maxPathLength=data;
        assignPathLength(root->left,pathLength(root->left));
        assignPathLength(root->right,pathLength(root->right));
    }
}

void removeNodes(node*root,int k)
{
    if(root==NULL)
    return;
    
    if(root->maxPathLength<k)
    {
        deleteTree(root);
        root=NULL;
        return;
    }
    
    root->flag=1;
    
    removeNodes(root->left,k-root->data);
    removeNodes(root->right,k-root->data);
}

void fun(node*root)
{
    if(root!=NULL)
    {
        if(root->flag==1)
        cout<<root->data<<" ";
        
        fun(root->left);
        fun(root->right);
    }
}

int main()
{
    int k = 45;
    node *root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    root->right->left = insert(6);
    root->right->right = insert(7);
    root->left->left->left = insert(8);
    root->left->left->right = insert(9);
    root->left->right->left = insert(12);
    root->right->right->left = insert(10);
    root->right->right->left->right = insert(11);
    root->left->left->right->left = insert(13);
    root->left->left->right->right = insert(14);
    root->left->left->right->right->left = insert(15);
    
    pathLength(root);
    assignPathLength(root,pathLength(root));
    
    removeNodes(root,k);
    fun(root);
}
