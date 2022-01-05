#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={3,5,6,3,2,1,8,0,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int *a=arr,*b=arr+n-1,sum=0,x=14,flag=0;
    
    for(int i=0;i<n;i++)
    sum+=arr[i];
    
    while(a<=b)
    {
        if(sum==x){
        flag=1;
        break;
        }
        
        else if(*a==0)
        a++;
        
        else if(*b==0)
        b--;
        
        else if(*a > *b)
        {
            if(sum - (*a) >=x){
            sum-= (*a);
                a++;
            }
            
            else if(sum - *b>=x){
            sum-= (*b);
                b--;
            }
            
            else
            break;
        }
        
        else
        {
            if(sum - (*b) >=x)
            {
                sum-= (*b);
                b--;
            }
            
            else if(sum - (*a) >=x)
            {
                sum-= (*a);
                a++;
            }
            
            else break;
        }
    }
    
    if(flag==0)
    cout<<"No such subarray";
    
    else
    {
        while(a<=b)
        {
            cout<<*a<<endl;
            a++;
        }
    }
}
