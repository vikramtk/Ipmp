#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={16, 17, 4, 3, 5, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int max=-99999;
    
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>max)
        {
            cout<<arr[i]<<endl;
            max=arr[i];
        }
    }
}
