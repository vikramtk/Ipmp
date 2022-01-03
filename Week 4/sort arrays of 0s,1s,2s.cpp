#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,0,0,2,1,2,0,0,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int n1=0,n2=0,n0=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        n0++;
        else if(arr[i]==1)
        n1++;
        else
        n2++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(n0){
        arr[i]=0;
        n0--;}
        else if(n1){
        arr[i]=1;
        n1--;}
        else
        arr[i]=2;
    }
    
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}
