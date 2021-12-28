#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(int arr[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        if(arr[i]==arr[n-1-i])
        continue;
        else
        return false;
    }
    return true;
}

void nextpalindrome(int arr[],int n)
{
    int mid,j,carry,i=0;
    
    if(n%2==0)
    mid=(n/2) - 1;
    else
    mid=n/2;
    
    while(1)                        //case 1
    {
        if(i==n)
        {
            cout<<pow(10,n)+1<<endl;
            return;
        }
        if(arr[i]==9){
            i++;
            continue;
        }
        else
        break;
    }
    
    if(ispalindrome(arr,n))         //case 2
    {
        i=mid;
        j=n-mid-1;
        
        if(i==j){                   //odd number of digits
        arr[i]=(arr[i]+1)%10;
        if(arr[i]==0)
        carry=1;
        else
        carry=0;
        }
        
        else                        //even no of digits
        {
            carry=1;
            i++;
            j--;
        }
        
        while(carry==1)
        {
            i--;
            j++;
            arr[i]=(arr[i]+1)%10;
            arr[j]=arr[i];
            
            if(arr[i]==0)
            carry=1;
            else
            carry=0;
        }
        
        for(i=0;i<n;i++)
        cout<<arr[i];
        cout<<endl;
        return;
    }
    
    if(!ispalindrome(arr,n))                               //case 3
    {
        i=mid;
        j=n-mid-1;
        while(arr[i]==arr[j])
        {
            i--;j++;
        }
            
        if(arr[i]>arr[j])
        {
            while(i>=0)
            {
                arr[j]=arr[i];
                i--;
                j++;
            }
        }
        
        else
        {
            i=mid;
        j=n-mid-1;
        
        if(i==j){                   //odd number of digits
        arr[i]=(arr[i]+1)%10;
        if(arr[i]==0)
        carry=1;
        else
        carry=0;
        }
        
        else                        //even no of digits
        {
            carry=1;
            i++;
            j--;
        }
        
        while(carry==1)
        {
            i--;
            j++;
            arr[i]=(arr[i]+1)%10;
            arr[j]=arr[i];
            
            if(arr[i]==0)
            carry=1;
            else
            carry=0;
        }
        
        while(i>=0)
        {
            arr[j]=arr[i];
            i--;j++;
        }
        
        for(i=0;i<n;i++)
        cout<<arr[i];
        cout<<endl;
        return;
        }
        
        for(i=0;i<n;i++)
        cout<<arr[i];
        cout<<endl;
    }
}

int main()
{
    int arr1[]={9,9,9,9,9};
    int arr2[]={1,2,2,1};
    int arr3[]={3,6,5,9,5,7,1};
    
    nextpalindrome(arr1,sizeof(arr1)/sizeof(arr1[0]));
    nextpalindrome(arr2,sizeof(arr2)/sizeof(arr2[0]));
    nextpalindrome(arr3,sizeof(arr3)/sizeof(arr3[0]));
}
