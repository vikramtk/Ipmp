#include<bits/stdc++.h>
#include "trees.h"
using namespace std;

node* arr[100]={NULL};
void nextp(node *p)
{
    static int i=0;
    if(p!=NULL)
    {
        nextp(p->left);
        arr[i++]=p;
        nextp(p->right);
    }
}

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
    
    nextp(root);
    
    int j=0;
    while(arr[j+1]!=NULL)
    {
        arr[j]->next=arr[j+1];
        j++;
    }
    arr[j]->next=NULL;
    
    node*cur=root;
    while(cur->left!=NULL)
    cur=cur->left;
    
    while(cur!=NULL)
    {
        cout<<cur->data<<endl;
        cur=cur->next;
    }
    cout<<"NULL";
}
