#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

int main()
{
    linkedlist L;
    for(int i=0;i<10;i++)
    L.insert(i*i -1);
    
    L.print();
    
    int size=L.length();
    int a[size];
    
    Node*cur=L.head;
    for(int i=0;i<size;i++)
    {
        a[i]=cur->data;
        cur=cur->next;
    }
    
    cur=L.head;
    for(int i=0;i<size;i++)
    {
        cur->data=a[9-i];
        cur=cur->next;
    }
    
    cout<<"\nAfter reversing list itself"<<endl;
    L.print();
    return 0;
}
