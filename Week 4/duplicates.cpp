//O(N) time and O(1) space

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,0,6,0,6,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])]==0)
        continue;
        else if(arr[abs(arr[i])]>0)
        arr[abs(arr[i])]=-arr[abs(arr[i])];
        else{
        cout<<abs(arr[i]);
        arr[abs(arr[i])]=0;
        }
    }
}
