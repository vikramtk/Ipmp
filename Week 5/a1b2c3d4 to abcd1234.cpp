#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[]={'a','1','b','2','c','3','d','4'};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int shifts=0;
    
    for(int i=1;i<n && shifts<(n-2);i+=2)
    {
        int source=i;
        char item=arr[source];
        
        do{
            int target;
            if(source%2==0)
            target=source/2;
            else
            target=n/2 + source/2;
            
            char temp=arr[target];
            arr[target]=item;
            item=temp;
            shifts++;
            source=target;
        }while(i!=source);
    }
    
    for(int i=0;i<n;i++)
    cout<<arr[i];
}
