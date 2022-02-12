#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

struct lis{
    int data;
    lis*next;
}*head;

void push(int data)
{
    struct lis*l=new lis();
    l->data=data;
    l->next=NULL;
    
    if(head==NULL)
    head=l;
    
    else
    {
        l->next=head;
        head=l;
    }
}

node*maketree(int c)
{
    if(c<=0)
    return NULL;
    
    node*left=maketree(c/2);
    
    node*root=insert(head->data);
    head=head->next;
    root->left=left;
    
    root->right=maketree(c-c/2-1);
    
    return root;
}

int main()
{
    lis l;
    int c=0;
    for(int i=0;i<7;i++)
    push(7-i);
    
    lis*cur=head;
    while(cur!=NULL)
    {
        c++;
        cur=cur->next;
    }
    
    node*m=maketree(c);
    inorder(m);
    cout<<endl;
    preorder(m);
    cout<<endl;
    postorder(m);
}

/*

#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

struct lis{
    int data;
    lis*next;
}*head;

void push(int data)
{
    struct lis*l=new lis();
    l->data=data;
    l->next=NULL;
    
    if(head==NULL)
    head=l;
    
    else
    {
        l->next=head;
        head=l;
    }
}

int fun(int d)
{
    lis*cur=head;
    
    for(int i=0;i<d;i++)
    cur=cur->next;
    
    return cur->data;
}

node*maketree(int start,int end)
{
    if(start==end)
    return insert(fun(start));
    
    if(start==end-1)
    {
        node*p=insert(fun(end));
        p->left=insert(fun(start));
        return p;
    }
    
    int mid=(start+end)/2;
    
    node*m=insert(fun(mid));
    
    m->left=maketree(start,mid-1);
    m->right=maketree(mid+1,end);
    
    return m;
}

int main()
{
    lis l;
    int c=0;
    for(int i=0;i<7;i++)
    push(7-i);
    
    lis*cur=head;
    while(cur!=NULL)
    {
        c++;
        cur=cur->next;
    }
    
    node*m=maketree(0,c-1);
    inorder(m);
    cout<<endl;
    preorder(m);
    cout<<endl;
    postorder(m);
}

*/
