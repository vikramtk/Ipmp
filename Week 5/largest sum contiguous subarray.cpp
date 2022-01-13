#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int maxendinghere=0;
    int maxsofar=0;
    
    for(int i=0;i<n;i++)
    {
        maxendinghere+=arr[i];
        
        if(maxsofar<maxendinghere)
        maxsofar=maxendinghere;
        
        if(maxendinghere<0)
        maxendinghere=0;
    }
    
    cout<<maxsofar;
}
