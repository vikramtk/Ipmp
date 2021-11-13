#include<bits/stdc++.h>
using namespace std;

void countingsort(int arr[],int n)
{
    int bucket[10];
    for(int i=0;i<10;i++)
    bucket[i]=0;
    
    for(int i=0;i<n;i++)
    bucket[arr[i]]++;
    
    int sum=0;
    
    for(int i=0;i<10;i++)
    {
        sum+=bucket[i];
        bucket[i]=sum;
    }
    
    int out[n];
    for(int i=0;i<n;i++)
    {
        out[bucket[arr[i]]-1]=arr[i];
        bucket[arr[i]]--;
    }
    
    for(int i=0;i<n;i++)
    printf("%d ",out[i]);
}

int main()
{
    int arr[]={3,6,5,4,7,9,1,3,0,9,4,2,7,6,4,2,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    countingsort(arr,size);
    return 0;
}
