#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

Node* merge(Node* a,Node *b)
{
    Node* result=NULL;
    
    if(a==NULL)
    return b;
    else if(b==NULL)
    return a;
    
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    }
    
    else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void split(Node* source,Node **f,Node **b)
{
    Node* fast;
    Node* slow;
    
    slow=source;
    fast=source->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *f=source;
    *b=slow->next;
    
    slow->next=NULL;
}

void mergesort(Node** n)
{
    Node* head = *n;
    Node* a,*b;
    
    if(head==NULL || head->next == NULL)
    return;
    
    split(head,&a,&b);
    
    mergesort(&a);
    mergesort(&b);
    
    *n=merge(a,b);
}

int main()
{
    linkedlist L;
    
    L.insert(3);
    L.insert(5);
    L.insert(4);
    L.insert(1);
    L.insert(8);
    L.insert(0);
    L.insert(9);
    L.insert(5);
    
    L.print();
    
    mergesort(&L.head);

    cout<<endl;
    L.print();
}
