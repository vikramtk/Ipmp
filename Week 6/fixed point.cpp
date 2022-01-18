#include<bits/stdc++.h>
using namespace std;

int fixedpointsearch(int arr[],int l,int r)
{
    int mid=(l+r)/2;
    
    if(arr[mid]==mid)
    return mid;
    
    else if(arr[mid]<mid)
    return fixedpointsearch(arr,mid,r);
    
    else if(arr[mid]>mid)
    return fixedpointsearch(arr,l,mid);
    
    return -1;
}

int main()
{
    int arr[]={-10,-5,-1,0,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<fixedpointsearch(arr,0,n-1);
}
