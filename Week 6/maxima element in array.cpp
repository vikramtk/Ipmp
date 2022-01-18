#include<bits/stdc++.h>
using namespace std;

int maxima(int arr[],int l,int r,int n)
{
    int mid;
    if((l+r)%2==0)
    mid=(l+r)/2;
    else
    mid=((l+r)/2)+1;
    
    if(mid==0 || mid==(n-1) || (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]))
    return arr[mid];
    
    else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
    return maxima(arr,l,mid,n);
    
    else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
    return maxima(arr,mid,r,n);
    
    else
    return -1;
}

int main()
{
    int arr[]={8, 10, 20, 80, 100, 200, 400, 500,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<maxima(arr,0,n-1,n);
}
