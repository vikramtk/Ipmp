#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int min=arr[0];
    
    int diff;
    int max=0;
    for(int i=1;i<n;i++)
    {
        diff=arr[i]-min;
        if(max<diff)
        max=diff;
        if(arr[i]<min)
        min=arr[i];
    }
    cout<<max;
}
