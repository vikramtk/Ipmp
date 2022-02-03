#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

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
    
    queue<node*> q;
    q.push(root);
    
    while(q.size()!=0)
    {
        if(q.front()->left!=NULL)
        q.push(q.front()->left);
        
        if(q.front()->right!=NULL)
        q.push(q.front()->right);
        
        cout<<q.front()->data<<endl;
        q.pop();
    }
}
