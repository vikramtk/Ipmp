#include<bits/stdc++.h>
#include "bst.h"
using namespace std;

bool find(BST*root,int sum,unordered_set<int>&set)
{
    if(root==NULL)
    return 0;
    
    if(find(root->left,sum,set))
    return 1;
    
    if(set.find(sum-root->data) != set.end())
    {
        cout<<root->data<<" "<<sum-root->data;
        return 1;
    }
    
    else
    set.insert(root->data);
    
    return find(root->right,sum,set);
}

void findpair(BST*root,int sum)
{
    unordered_set<int> set;
    
    if(!find(root,sum,set))
    cout<<"No such pair found";
}

int main()
{
    BST b,*root=NULL;
    root=b.insert(root,15);
    b.insert(root,10);
    b.insert(root,20);
    b.insert(root,8);
    b.insert(root,12);
    b.insert(root,16);
    b.insert(root,25);
    
    findpair(root,33);
}

/*
#include<bits/stdc++.h>
#include "bst.h"
using namespace std;

pair<int,int> p;

void findother(BST*ogroot,int x1,int x2)
{
    while(ogroot!=NULL)
    {
        if(ogroot->data>x2)
        ogroot=ogroot->left;
        
        else if(ogroot->data<x2)
        ogroot=ogroot->right;
        
        else
        {
            p.first=x1;
            p.second=x2;
            return;
        }
        
    }
}

void findpair(BST* root,int x,BST* ogroot)
{
    if(root!=NULL)
    {
        findpair(root->left,x,ogroot);
        if(root->data!=x-root->data)
        findother(ogroot,root->data,x-root->data);
        findpair(root->right,x,ogroot);
    }
}

int main()
{
    BST b,*root=NULL;
    root=b.insert(root,15);
    b.insert(root,10);
    b.insert(root,20);
    b.insert(root,8);
    b.insert(root,12);
    b.insert(root,16);
    b.insert(root,25);
    p={-1,-1};
    int x=33;
    
    findpair(root,x,root);
    cout<<p.first<<" "<<p.second;
}
*/
