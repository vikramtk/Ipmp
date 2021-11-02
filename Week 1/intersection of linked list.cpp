#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

int main()
{
    linkedlist L;
    L.insert(8);
    L.insert(5);
    L.insert(4);
    L.insert(3);
    L.insert(10);
    
    linkedlist L2;
    L2.insert(1);
    
    L2.head->next=L.head->next->next;
    
    int d=L.length() - L2.length();
    
    Node *cur=L.head;
    Node *cur2=L2.head;
    
    if(d>=0){
    for(int i=0;i<d;i++)
    cur=cur->next;
    }
    
    else if(d<0){
    d=-d;
    for(int i=0;i<d;i++)
    cur2=cur2->next;}
    
    while(cur!=NULL && cur2!=NULL)
    {
        if(cur==cur2)
        {
            cout<<"Intersection is "<<cur->data;
            return 0;
        }
        cur=cur->next;
        cur2=cur2->next;
    }
    
    cout<<"No intersection";
    return 0;
}
