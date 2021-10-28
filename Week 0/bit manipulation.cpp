/*Given an array of positive integers. 
All numbers occur an even number of times except one number which occurs an odd number of times. 
Find the number in O(n) time & constant space.*/

#include<bits/stdc++.h>
using namespace std;

void func(int a[],int n)
{
    int temp=0;
    
    for(int i=0;i<n;i++)
        temp=temp^a[i];
    
    cout<<temp;
}

int main()
{
    int arr[]={1,4,5,6,3,4,1,3,5,7,3,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    func(arr,size);
}
