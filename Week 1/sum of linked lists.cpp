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
    L.insert(9);
    L.insert(3);
    L.insert(7);
    L.insert(9);
    
    linkedlist M;
    M.insert(6);
    M.insert(3);
    M.insert(4);  //9379+634=10013
    
    L.print();
    cout<<"\n+\n";
    M.print();
    int l1=L.length();
    int l2=M.length();
    
    int a[l1],b[l2];
    
    Node*cur=L.head;
    
    for(int i=0;i<l1;i++)
    {
        a[l1-i-1]=cur->data;
        cur=cur->next;
    }
    
    cur=M.head;
    
    for(int i=0;i<l2;i++)
    {
        b[l2-i-1]=cur->data;
        cur=cur->next;
    }
    
    L.deletelist();
    int sum,carry=0;
    for(int i=0;i<l1 && i<l2 ;i++)
    {
        sum=(a[i]+b[i]+carry)%10;
        carry=(a[i]+b[i]+carry)/10;
        L.insert(sum);
    }
    
    if(l1>l2){
    while(l1>l2){
        L.insert((a[l2]+carry)%10);
        carry=(a[l2]+carry)/10;
        l2++;
    }}
    
    else{
    while(l1<l2){
        L.insert((b[l2]+carry)%10);
        carry=(b[l2]+carry)/10;
        l1++;
    }}
    
    if(carry>0){
        while((carry/10)>0)
        L.insert(carry/10);}
        
    if(carry>0)
        L.insert(carry);
    cout<<"\n=\n";
    printreverse(L.head);
}
