#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

void triplet(Node*a,Node*bhead,Node*chead,int n)
{
    while(a!=NULL)
    {
        Node *b=bhead;
        Node *c=chead;
        
        while(b!=NULL && c!=NULL)
        {
        if(a->data + b->data + c->data == n)
        {
            cout<<"Triplet found : "<<a->data<<'\t'<<b->data<<'\t'<<c->data;
            exit(0);
        }
        
        else if(a->data + b->data + c->data < n)
        c=c->next;
        
        else b=b->next;
        }
        
        a=a->next;
    }
}

int main()
{
    int n;
    linkedlist A,B,C;
    
    A.insert(5);
    A.insert(3);
    A.insert(7);
    A.insert(12);
    
    for(int i=0;i<10;i++)
    {
        B.insert(2*(10-i));  //B in descending order
        C.insert(3*i);       //C in ascending(B and C sorted)
    }
    
    cin>>n;
    
    triplet(A.head,B.head,C.head,n);
    cout<<"Triplet not found for "<<n;
}
