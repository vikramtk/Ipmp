#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={ 2, 3, -7, 6, 8, 1, -10, 15 };
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            int temp=arr[i];
            arr[j]=arr[i];
            arr[i]=temp;
            j++;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(abs(arr[i])-1 < n && arr[abs(arr[i])-1]>0)
        arr[abs(arr[i])-1]=-arr[abs(arr[i]-1)];
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0){
        cout<<i+1;
        return 0;
        }
    }
}
