#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={12, 4, 78, 90, 45, 23};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int ans=0,count=1;
    
    for(int i=1;i<n-1;i++){
    count++;
    ans=max({ans,count});
    cout<<ans<<endl;
    
    if(arr[i]<=arr[i-1] && arr[i+1]>=arr[i])
    count=1;
    }
    
    if(n>=3)
    {
        count++;
        
        if(arr[n-2]<arr[n-3] && arr[n-1]>arr[n-2])
        count=1;
    }
    
    ans=max({ans,count});
    cout<<ans;
}
