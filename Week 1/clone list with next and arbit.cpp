//Clone a linked list with next and arbit pointer in O(n) time

#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

int main()
{
    linkedlist L;
    L.insert(1);
    L.insert(2);
    L.insert(3);
    L.insert(4);
    
    L.head->arbit=L.head->next->next;
    L.head->next->arbit=L.head->next->next->next;
    L.head->next->next->arbit=L.head->next;
    L.head->next->next->next->arbit=L.head;
    
    Node *cur=L.head;
    
    while(cur!=NULL)
    {
        Node * newnode = new Node(cur->data);
        newnode->next=cur->next;
        cur->next=newnode;
        cur=cur->next->next;
    }
    
    cur=L.head;
    
    for(int i=0;i<(L.length()/2);i++)
    {
        cur->next->arbit=cur->arbit->next;
        cur=cur->next->next;
    }
    
    Node *temp=L.head->next;
    cur=L.head;
    
    
    while(cur!=NULL)
    {
        cur->next=cur->next->next;
        cur=cur->next;
    }
    
    while(temp!=NULL)
    {
        temp->next=temp->next->next;
        temp=temp->next;
    }
    
    return 0;
}
