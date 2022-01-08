#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,5,4,2,7,8,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int incl=arr[0],excl=0;
    
    for(int i=1;i<n;i++)
    {
        int temp=incl;
        incl=excl+arr[i];
        excl=max({temp,excl});
    }
    
    cout<<max({incl,excl});
}
