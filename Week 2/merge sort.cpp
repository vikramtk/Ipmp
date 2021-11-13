#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int i,j,k;
    
    int A[n1],B[n2];
    
    for(i=0;i<n1;i++)
    {
        A[i]=arr[l+i];
    }
    
    for(j=0;j<n2;j++)
    {
        B[j]=arr[m+1+j];
    }
    
    i=0;
    j=0;
    k=l;
    
    while(i<n1 && j<n2)
    {
        if(A[i]<B[j]){
        arr[k]=A[i];
        i++;
        }
        else{
        arr[k]=B[j];
        j++;
        }
        k++;
    }
    
    while(j<n2)
    {
        arr[k]=B[j];
        j++;
        k++;
    }
    
    while(i<n1)
    {
        arr[k]=A[i];
        i++;
        k++;
    }
}

void mergesort(int arr[],int l,int r)
{
    if(r>l)
    {
    int m=l+((r-l)/2);
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
    }
    else
    return;
}

int main()
{
    int arr[]={4,6,2,3,1,7,9,0,8,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,size-1);
    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<'\t';
}
