#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    
        srand(time(0));
    for(int i=n-1;i>=1;i--)
    {
        int x=rand()%n;
        int temp=arr[i];
        arr[i]=arr[x];
        arr[x]=temp;
    }
    
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}
