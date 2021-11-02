//Check if a singly linked list is a palindrome
//What i've done is store initial half elements in an array and check the data of the right half of linked list with array(backwards)

#include<bits/stdc++.h>
#include "classes.h"
using namespace std;

int main()
{
    linkedlist L;
    L.insert(5);
    L.insert(4);
    L.insert(3);
    L.insert(4);
    L.insert(5);
    int n=L.length()/2;
    int a[n];
    Node *cur=L.head;
    a[0]=cur->data;
    for(int i=1;i<=n;i++)
    {
        a[i]=cur->data;
        cur=cur->next;
    }
    if(L.length()%2==1)
    cur=cur->next;
    for(int i=0;i<n;i++)
    {
        if(cur->data != a[n-i])
        {
            cout<<"Not a palindrome";
            return 0;
        }
        cur=cur->next;
    }
    cout<<"Palindrome";
    return 0;
}
