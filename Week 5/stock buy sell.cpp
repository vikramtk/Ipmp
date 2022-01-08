#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={ 100, 180, 260, 310, 40, 535, 695 };
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int profit=0;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        profit+=(arr[i]-arr[i-1]);
    }
    
    cout<<profit;
}
