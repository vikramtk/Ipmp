#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int index=0,count=1;
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]==arr[i])
        count++;
        
        else
        {
            count--;
            if(count==0){
            index=i+1;
            count=1;}
        }
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[index])
        count++;
    }
    
    if(count>(n/2))
    cout<<arr[index];
    
    else
    cout<<"No majority element";
}
