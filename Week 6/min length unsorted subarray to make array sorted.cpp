#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={0, 1, 15, 25, 6, 7, 30, 40, 50};
    int s,e,s2=-1,e2=-1,n=sizeof(arr)/sizeof(arr[0]),min=99999,max=-99999;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]<arr[i])
        {
            s=i;
            break;
        }
    }
    
    for(int i=n-1;i>0;i--)
    {
        if(arr[i-1]>arr[i])
        {
            e=i;
            break;
        }
    }
    
    for(int i=s;i<=e;i++)
    {
        if(arr[i]<min)
        min=arr[i];
        
        if(arr[i]>max)
        max=arr[i];
    }
    
    for(int i=0;i<s;i++)
    {
        if(arr[i]>min)
        {
            s2=i;
            break;
        }
    }
    if(s2==-1)
    s2=s;
    
    for(int i=n-1;i>e;i--)
    {
        if(arr[i]<max)
        {
            e2=i;
            break;
        }
    }
    if(e2==-1)
    e2=e;
    
    cout<<s2<<e2;
}
