//Traverse array only once

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,0,0,1,0,1,0,0,0,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int i=0,j=n-1;
    
    while(i<j)
    {
        if(arr[i]==0)
        i++;
        
        else if(arr[j]==1)
        j--;
        
        else
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    for(int i=0;i<n;i++)
    cout<<arr[i];
}
