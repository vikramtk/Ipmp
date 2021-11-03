#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

int main()
{
    int flag=0;
    linkedlist A,B,U,I;
    for(int i=0;i<10;i++)
        A.insert(i);
    for(int i=0;i<10;i++)
        B.insert(2*i);
    Node *cur1=A.head;
    Node* cur2=B.head;
    while(cur1!=NULL)
    {
        U.insert(cur1->data);
        cur1=cur1->next;
    }
    cur1=A.head;
    while(cur2!=NULL)
    {
        while(cur1->next!=NULL)
        {
            if(cur1->data==cur2->data){
            I.insert(cur2->data);
            flag=1;
            break;
            }
            cur1=cur1->next;
        }
        if(flag==0)
        U.insert(cur2->data);
        cur1=U.head;
        cur2=cur2->next;
        flag=0;
    }
    cout<<"A\n";
    A.print();
    cout<<"\nB\n";
    B.print();
    cout<<"\nUnion\n";
    U.print();
    cout<<"\nIntersection\n";
    I.print();
}
