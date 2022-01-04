#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Arr[]={1,2,0,9,8,0,6,0,0,4,3,1,0};
    int n=sizeof(Arr)/sizeof(Arr[0]),count=0;
    
    for(int i=0;i<n;i++)
    if(Arr[i]==0)
    count++;
    
    int j=-1;
    
    for(int i=0;i<n;i++)
    {
        if(Arr[i]!=0)
        {
            j++;
            Arr[j]=Arr[i];
        }
    }
    
    while((j++)<n)
    {
        Arr[j]=0;
    }
    
    for(int i=0;i<n;i++)
    cout<<Arr[i]<<endl;
}
