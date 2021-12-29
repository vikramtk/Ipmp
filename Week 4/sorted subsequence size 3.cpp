/* Given an array of n integers, find the 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time. 
If there are multiple such triplets, then print any one of them. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={12, 11, 10, 5, 6, 2, 30};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int smaller[n],greater[n];
    smaller[0]=-1;
    int min=0,max=n-1;
    greater[max]=-1;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]<=arr[min])
        {
            min=i;
            smaller[i]=-1;
        }
        else
        smaller[i]=min;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=arr[max])
        {
            max=i;
            greater[i]=-1;
        }
        else
        greater[i]=max;
    }
    
    for(int i=0;i<n;i++)
    {
        if(smaller[i]!=-1 && greater[i]!=-1){
        cout<<arr[smaller[i]]<<arr[i]<<arr[greater[i]];
        return 0;
        }
    }
    cout<<"No such subsequence";
    return 0;
}
