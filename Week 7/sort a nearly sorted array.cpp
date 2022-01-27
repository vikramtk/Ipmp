#include<bits/stdc++.h>
#include "heap.h"
using namespace std;

int main()
{
    int a[]={10, 9, 8, 7, 4, 70, 60, 50};
    int n=sizeof(a)/sizeof(a[0]);
    int i,k=4;
    
    minheap m(k+1);
    for(i=0;i<k+1;i++)
    {
        m.insert(a[i]);
    }
    
    for(int p=0;p<n;p++)
    {
        a[p]=m.extractmin();
        m.insert(a[i]);
        i++;
    }
    
    for(i=0;i<n;i++)
    cout<<a[i]<<endl;
}
