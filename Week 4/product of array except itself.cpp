#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={10, 3, 5, 6, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int product[n];
    int temp=1;
    for(int i=0;i<n;i++)
    {
        product[i]=temp;
        temp=temp*arr[i];
    }
    temp=1;
    for(int i=n-1;i>=0;i--)
    {
        product[i]=product[i]*temp;
        temp=temp*arr[i];
    }
    
    for(int i=0;i<n;i++)
    cout<<product[i]<<endl;
}
