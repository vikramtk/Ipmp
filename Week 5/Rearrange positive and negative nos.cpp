#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={-1, 2, -3, -4, -5, 6, -7, 8, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(arr[j]<0)
        {
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    
    int pos=i+1,neg=0;
    
    while(pos<n && neg<pos && arr[neg]<0)
    {
        int temp=arr[pos];
        arr[pos]=arr[neg];
        arr[neg]=temp;
        
        pos++;
        neg+=2;
    }
    
    for(int j=0;j<n;j++)
    cout<<arr[j]<<endl;
}
