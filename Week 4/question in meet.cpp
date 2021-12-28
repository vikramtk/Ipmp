/* Delete middle node: Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node. 
Input: the node c from the linked list a->b->c->d->e->f Result: nothing is returned, but the new linked list looks like a->b->d->e->f */

#include<bits/stdc++.h>
#include"classes.h"
using namespace std;

int main()
{
    linkedlist l;
    for(int i=0;i<10;i++)
    l.insert(i);
    
    l.print();
    
    cout<<endl;
    //deleting 2(head->next->next)
    Node*access = l.head->next->next;
    
    Node*temp=access->next;
    access->data=temp->data;
    access->next=temp->next;
    temp->next=NULL;
    free(temp);
    
    l.print();
    return 0;
}
