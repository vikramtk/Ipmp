#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={4,6,4,7,5,6,7,9,0,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    map <int,int> m;
    for(int i=0;i<n;i++)
    m[arr[i]]++;
    
    for(auto& x : m)
    {
        if(x.second==1)
        cout<<x.first<<endl;
    }
    
    return 0;
}
