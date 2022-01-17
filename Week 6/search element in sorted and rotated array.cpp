#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int l,int r,int x)
{
    int mid=(l+r)/2;
    if(arr[mid]==x)
    return mid;
    
    if(l<r){
    if(arr[l]<arr[mid]){
    if(arr[l]<=x && arr[mid]>=x)
    search(arr,l,mid,x);
    else
    search(arr,mid+1,r,x);}
    
    else{
        if(arr[mid+1]<=x && arr[r]>=x)
    search(arr,mid+1,r,x);
    else
    search(arr,l,mid,x);
    }
    }
    
    else
    return -1;
}

int main()
{
    int arr[]={4,5,6,7,8,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int x=2;
    cout<<search(arr,0,n-1,x);
}
