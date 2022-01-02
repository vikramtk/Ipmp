#include<bits/stdc++.h>
using namespace std;

int main()
{
    int count=0,n=10;
    
    for(int i=1;i<n;i++)
    for(int j=i+1;j<n;j++)
    {
        int y=sqrt((i*i)+(j*j));
        
        if(y*y == (i*i)+(j*j) && y<=n)
        count++;
    }
    
    cout<<count;
}
