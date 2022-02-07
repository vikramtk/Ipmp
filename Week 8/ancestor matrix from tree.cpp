#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

void ancestor(node*p)
{
    int n=size(p);
    int arr[n][n];
    int included[n]={0};
    
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    arr[i][j]=0;
    
    stack<node*> s;
    s.push(p);
    included[p->data]=1;
    p->visited=1;
    
    while(s.size()!=0)
    {
        while(s.top()->left!=NULL && s.top()->left->visited!=1)
        {
            s.push(s.top()->left);
            s.top()->visited=1;
            included[s.top()->data]=1;
        }
        
        if(s.top()->right!=NULL && s.top()->right->visited!=1)
        {
            s.push(s.top()->right);
            included[s.top()->data]=1;
            s.top()->visited=1;
            continue;
        }
        
        if(s.top()->left==NULL && s.top()->right==NULL)
        {
            for(int i=0;i<n;i++)
            if(included[i])
            arr[i][s.top()->data]=1;
            
            included[s.top()->data]=0;
            s.pop();
            continue;
        }
        
        included[s.top()->data]=0;
        for(int i=0;i<n;i++)
            if(included[i])
            arr[i][s.top()->data]=1;
        s.pop();
    }
    
    for(int i=0;i<n;i++)
    arr[i][i]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    node*root;
    root=insert(5);
    root->left=insert(1);
    root->right=insert(2);
    root->left->left=insert(0);
    root->left->right=insert(4);
    root->right->left=insert(3);
    
    ancestor(root);
}
