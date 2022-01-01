#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,2,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]),sum=0;
    
    for(int i=0;i<n;i++)
    sum+=arr[i];
    
    int sum2=arr[0];
    
    for(int i=1;i<n-1;i++)
    {
        if(sum2==(sum-arr[i]-sum2))
        cout<<arr[i];
        
        else
        sum2+=arr[i];
    }
}
