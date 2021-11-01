//Print reverse of linked list without actuallyu reversing

#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

void printreverse(Node* n)
{
    if(n->next!=NULL)
    printreverse(n->next);
    printf("%d ",n->data);
}

int main()
{
    linkedlist L;
    for(int i=0;i<10;i++)
    L.insert(i*i -1);
    printreverse(L.head);
    
    return 0;
}
