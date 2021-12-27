#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,2,3,4,5,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int xor2,x=0,y=0;
    for(int i=0;i<n;i++)
    xor2=xor2^arr[i];
    
    int setbit=xor2 & ~(xor2-1);
    
    for(int i=0;i<n;i++)
    {
       if(arr[i] & setbit)
       x=x^arr[i];
       
       else
       y=y^arr[i];
    }
    cout<<x<<endl<<y;
}
