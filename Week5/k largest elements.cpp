#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={4,6,7,3,2,8,9,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int k=4;
    
    sort(arr,arr+n);
    
    for(int i=n-k;i<n;i++)
    cout<<arr[i]<<endl;
}
