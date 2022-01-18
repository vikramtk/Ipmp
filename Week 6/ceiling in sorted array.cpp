#include<bits/stdc++.h>
using namespace std;

int ceiling(int arr[],int l,int r,int x)
{
    int mid=(l+r)/2;
    if(arr[mid]>x && arr[mid-1]<=x)
    return arr[mid];
    
    else if((arr[mid]<=x && arr[mid+1]>x))
    return arr[mid+1];
    
    else if(arr[mid]>x && arr[mid-1]>x)
    return ceiling(arr,l,mid,x);
    
    else if(arr[mid]<=x && arr[mid+1]<=x)
    return ceiling(arr,mid,r,x);
    
    return -1;
}

int main()
{
    int arr[]={1, 2, 8, 10, 10, 12, 19};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int x=13;
    if(arr[n-1]<x)
    cout<<"Ceiling doesnt exist";
    else if(arr[0]>x)
    cout<<arr[0];
    else
    cout<<ceiling(arr,1,n-1,x);
}
