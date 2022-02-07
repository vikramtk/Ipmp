Note:There is an element travelled inside class tree and if you want to check more than one sum,then between process,make all travelled of nodes=0

#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

int findnoofleaves(node*p)
{
    if(p==NULL)
    return 0;
    
    if(p->left==NULL && p->right==NULL)
    return 1;
    
    return findnoofleaves(p->left)+findnoofleaves(p->right);
}

int pathsum(node*p,int x)
{
    int arr[findnoofleaves(p)];
    int i=0,sum=p->data;
    
    stack<node*> s;
    s.push(p);
    p->travelled=1;
    while(s.size()!=0)
    {
        while(s.top()->left!=NULL && s.top()->left->travelled!=1){
        s.push(s.top()->left);
        s.top()->travelled=1;
        sum+=s.top()->data;}
        
        if(s.top()->right!=NULL && s.top()->right->travelled!=1){
        s.push(s.top()->right);
        sum+=s.top()->data;
        s.top()->travelled=1;
        continue;}
        
        if(s.top()->left==NULL && s.top()->right==NULL)
        {
            s.top()->travelled=1;
            arr[i++]=sum;
            sum-=s.top()->data;
            s.pop();
            continue;
        }
        
        sum-=s.top()->data;
        s.pop();
    }
    
    for(int j=0;j<i;j++)
    if(arr[j]==x)
    return 1;
    
    return 0;
}

int main()
{
    node*root=insert(50);
    root->left=insert(7);
    root->right=insert(2);
    root->left->left=insert(3);
    root->right->left=insert(1);
    root->left->right=insert(5);
    root->right->right=insert(30);
    root->right->right->left=insert(4);
    
    cout<<pathsum(root,86);
}
