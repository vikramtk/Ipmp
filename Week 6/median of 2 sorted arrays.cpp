#include<bits/stdc++.h>
using namespace std;

int median(int arr1[],int arr2[],int l1,int r1,int l2,int r2)
{
    if(r1-l1 == 1 && r2-l2 ==1)
    return (max(arr1[l1],arr2[l2])+min(arr1[r1],arr2[r2]))/2;
    
    int mid1=(l1+r1)/2,mid2=(l2+r2)/2;
    
    if(arr1[mid1]==arr2[mid2])
    return arr1[mid1];
    
    else if(arr1[mid1]>arr2[mid2])
    return median(arr1,arr2,l1,mid1,mid2,r2);
    
    else
    return median(arr1,arr2,mid1,r1,l2,mid2);
}

int main()
{
    int arr1[]={3,5,6,12,45};
    int arr2[]={4,7,9,11,55};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    cout<<median(arr1,arr2,0,n-1,0,n-1);
}
