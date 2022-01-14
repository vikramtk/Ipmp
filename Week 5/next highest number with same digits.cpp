#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,8,4,9,8,7,6};  //We can get input as int and convert it as array also
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    for(i=n-1;i>=1;i--)
    {
        if(arr[i-1]<arr[i])
    break;
    }
    
    int min=99999,index=-1;
    for(int j=i;j<n;j++)
    {
        if(arr[j]<min && arr[j]>arr[i-1]){
        min=arr[j];
        index=j;}
    }
    
    if(index!=-1)
    {
    int temp=arr[index];
    arr[index]=arr[i-1];
    arr[i-1]=temp;
    
    for(int j=i;j<n;j++)
    for(int k=i;k<n-1;k++)
    {
        if(arr[k+1]<arr[k])
        {
            temp=arr[k+1];
            arr[k+1]=arr[k];
            arr[k]=temp;
        }
    }
    
    for(i=0;i<n;i++)
    cout<<arr[i];
    }
}
