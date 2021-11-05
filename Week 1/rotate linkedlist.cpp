#include<bits/stdc++.h>
#include "classes.h"
using namespace std;


int main()
{
    linkedlist L;
    int k;
    
    for(int i=0;i<10;i++)
    L.insert(10*i);
    
    cin>>k;
    L.print();
    
    Node*prev=L.head;
    Node*cur=L.head;
    
    for(int i=0;i<k-1;i++)
    cur=cur->next;
    
    L.head=cur->next;
    cur->next=NULL;
    cur=L.head;
    
    while(cur->next!=NULL)
    cur=cur->next;
    
    cur->next=prev;
    
    cout<<"\nAfter rotating at "<<k<<endl;
    L.print();
}
