#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={3,5,6,3,2,1,8,0,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int d=4;
    int temp[d];
    
    for(int i=0;i<d;i++)
    temp[i]=arr[i];
    
    for(int i=0;i<n-d;i++)
    arr[i]=arr[i+d];
    
    for(int i=n-d;i<n;i++)
    arr[i]=temp[i-n+d];
    
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}
