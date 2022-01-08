#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=10;
    for(int i=0;i<n;i++)
    {
        if(arr[arr[i]]>0)
        arr[arr[i]]=-1 * k;
        
        else
        arr[arr[i]]--;
    }
    
    int min=0;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[min])
        min=i;
    }
    
    cout<<min;
}
