#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void post(node*p)
{
    if(p!=NULL)
    {
        post(p->right);
        if(p->right!=NULL || p->left!=NULL)
        cout<<p->data<<endl;
    }
}

void bfs(node* p)
{
    queue<node*> q;
    q.push(p);
    
    while(q.size()!=0)
    {
        if(q.front()->left==NULL && q.front()->right==NULL)
        cout<<q.front()->data<<endl;
        
        else if(q.front()->left!=NULL)
        q.push(q.front()->left);
        
        if(q.front()->right!=NULL)
        q.push(q.front()->right);
        
        q.pop();
    }
}

void dfs(node* p)
{
    stack<node*> s;
    s.push(p);
    
    while(s.size()!=0)
    {
        node*temp=s.top();
        s.pop();
        if(temp->left==NULL && temp->right==NULL)
        cout<<temp->data<<endl;
        
        if(temp->right!=NULL)
        s.push(temp->right);
        
        if(temp->left!=NULL)
        {
            s.push(temp->left);
            while(s.top()->left!=NULL)
            s.push(s.top()->left);
        }
    }
}

int main()
{
    node*root=insert(1);
    root->left=insert(2);
    root->left->left=insert(3);
    root->left->right=insert(4);
    root->right=insert(7);
    root->right->left=insert(5);
    root->right->right=insert(6);
    root->left->left->left=insert(8);
    root->left->left->right=insert(9);
    root->left->right->left=insert(10);
    root->right->left->right=insert(11);
    root->right->right->left=insert(12);
    
    cout<<root->data<<endl;
    
    node*cur=root->left;
    while(cur&&cur->left&&cur->left!=NULL){
    cout<<cur->data<<endl;
    cur=cur->left;
    }
    
    if(root->left!=NULL)
    bfs(root->left);
    
    if(root->right!=NULL)
    dfs(root->right);
    
    if(root->right!=NULL)
    post(root->right);
}
