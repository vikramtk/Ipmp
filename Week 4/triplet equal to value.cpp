#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,6,2,3,4,5,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int *a,*b,value=10;
    sort(arr,arr+n);
    
    for(int i=0;i<n-2;i++)
    {
        a=arr+i+1;
        b=arr+n-1;
        while(a<b)
        {
        if((*a + *b) == value-arr[i]){
        cout<<arr[i]<<","<<*a<<","<<*b;
        exit(0);
        }
        else if((*a + *b) < (value-arr[i]))
        a+=1;
        else
        b-=1;
        }
    }
    return 0;
}
