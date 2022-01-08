#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={3, 0, 2, 0, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int minimum[n],maximum[n];
    int max=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
        
        minimum[i]=max;
    }
    
    max=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>max)
        max=arr[i];
        
        maximum[i]=max;
    }
    int water=0;
    for(int i=0;i<n;i++)
    {
        water+=(min({minimum[i],maximum[i]})-arr[i]);
    }
    cout<<water;
}
