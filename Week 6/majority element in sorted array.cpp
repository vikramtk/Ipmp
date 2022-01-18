#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1, 2, 3, 3, 3, 3, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int x=3;
    if(arr[n/2]==x)
    cout<<true;
    else
    cout<<false;
}
