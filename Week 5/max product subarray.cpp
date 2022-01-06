#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2,0,-6,8,3,1,-4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int maxendinghere=arr[0],maxsofar=arr[0],minendinghere=arr[0];
    
    for(int i=1;i<n;i++)
    {
        int temp=max({arr[i],maxendinghere*arr[i],minendinghere*arr[i]});
        minendinghere=min({arr[i],maxendinghere*arr[i],minendinghere*arr[i]});
        maxendinghere=temp;
        maxsofar=max(maxsofar,temp);
    }
    
    cout<<maxsofar;
}
