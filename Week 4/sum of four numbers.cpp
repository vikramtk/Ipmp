#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={10,2,3,4,5,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int X=23;
    unordered_map <int, pair<int,int>> m;
    
    for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
    m[arr[i]+arr[j]]={i,j};
    
    for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
    {
        int sum=arr[i]+arr[j];
        
        if(m.find(X-sum)!=m.end())
        {
            pair<int,int> p = m[X-sum];
            if(p.first!=i && p.first!=j && p.second!=i && p.second!=j){
            cout<<arr[i]<<arr[j]<<arr[p.first]<<arr[p.second];
            return 0;
            }
        }
    }
}
