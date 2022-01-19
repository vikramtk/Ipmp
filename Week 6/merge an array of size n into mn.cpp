#include<bits/stdc++.h>
using namespace std;

int main()
{
   int NA=-1; 
   int arr[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
   int mn=sizeof(arr)/sizeof(arr[0]);
   int arr2[] = {5, 7, 9, 25};
   int n=sizeof(arr2)/sizeof(arr2[0]);
   int j=mn-1;
   for(int i=mn-1;i>=0;i--)
   {
       if(arr[i]!=NA)
       {
           arr[j--]=arr[i];
       }
   }
   
   int k=n;
   j=0;
   
   for(int i=0;i<mn;i++)
   {
       if(k>=mn)
       arr[i]=arr2[j++];
       
       else if(j>=n)
       arr[i]=arr[k++];
       
       else if(arr[k]<=arr2[j])
       arr[i]=arr[k++];
       
       else
       arr[i]=arr2[j++];
   }
    
   for(int i=0;i<mn;i++)
   cout<<arr[i]<<endl;
}
