/*Write a program to print the middle element of linked list
Note that head should be declared in puyblic in class linked list in the header file*/

#include<bits/stdc++.h>
#include "classes.h"
using namespace std;


int main()
{
    linkedlist L;
    for(int i=0;i<10;i++)
    L.insert(i*i - 1);
    
    cout<<"The middle element is ";
    Node *cur=L.head;
    for(int i=0;i<L.length()/2;i++)
    cur=cur->next;
    cout<<cur->data;
    
    L.deletenode(8);
    cout<<endl;

    cout<<"The middle element is ";
    cur=L.head;
    for(int i=0;i<L.length()/2;i++)
    cur=cur->next;
    cout<<cur->data;
    return 0;
}
