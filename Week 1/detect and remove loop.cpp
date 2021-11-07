//Note that for the header file in this program alone,there is a modification.In class Node,there is an additional element int flag to keep track of visited nodes

#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

void detect_remove_loop(Node *cur)
{
    if(cur->next==NULL)    //reached end of list
    {
        printf("There is no loop");
        return;
    }
    if(cur->next->flag==1)    //cur->next already visited
    {
        printf("Loop is detected and removed");
        cur->next=NULL;                         //remove loop linkage
        return;
    }
    cur->flag=1;
    detect_remove_loop(cur->next);
}

int main()
{
    linkedlist L;
    L.insert(1);
    L.insert(2);
    L.insert(3);
    L.insert(4);
    L.head->next->next->next->next=L.head->next;  //loop from 4 to 2
    
    detect_remove_loop(L.head);
    L.print();
}
