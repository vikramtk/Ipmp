#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    cout<<(((n+1)*(n+2))/2)-sum;
}
