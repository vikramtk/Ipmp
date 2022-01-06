#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int l,int m,int r)
{
    int i=l,k=l,j=m,invcount=0;
    
    while(i<=m-1 && j<=r)
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        
        else
        {
            temp[k++]=arr[j++];
            invcount+=(m-i);
        }
    }
    
    while(i<=m-1)
    temp[k++]=arr[i++];
    
    while(j<=r)
    temp[k++]=arr[j++];
    
    for(int i=l;i<=r;i++)
    arr[i]=temp[i];
    
    return invcount;
}

int mergesort(int arr[],int temp[],int left,int right)
{
    int invcount=0;
    if(right>left)
    {
        int mid=(left+right)/2;                   //mid declaration
        invcount+=mergesort(arr,temp,left,mid);
        invcount+=mergesort(arr,temp,mid+1,right);
        invcount+=merge(arr,temp,left,mid+1,right);
    }
    return invcount;
}

int utility(int arr[],int n)
{
    int temp[n];
    return mergesort(arr,temp,0,n-1);
}

int main()
{
    int arr[]={5,3,6,8,9,1,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    cout<<utility(arr,n);
}
