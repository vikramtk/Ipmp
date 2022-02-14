#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *prev,*next;
};

void push(node **head,int data)
{
    node*newnode=new node();
    
    newnode->prev=NULL;
    newnode->data=data;
    
    newnode->next=*head;
    
    if(*head!=NULL)
    (*head)->prev=newnode;
    
    *head=newnode;
}

node* dllTree(node **head,int n)
{
    if(n<=0)
    return NULL;
    
    node*left=dllTree(head,n/2);
    
    node*root=*head;
    
    root->prev=left;
    *(head)=(*head)->next;
    
    root->next=dllTree(head,n-n/2-1);
    
    return root;
}

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->prev);
        cout<<root->data<<" ";
        inorder(root->next);
    }
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->prev);
        preorder(root->next);
    }
}

int main()
{
    node*head=NULL;
    
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    int c=0;
    node*cur=head;
    while(cur!=NULL)
    {
        c++;
        cur=cur->next;
    }
    
    node*root=dllTree(&head,c);
    
    inorder(root);
    preorder(root);
}
