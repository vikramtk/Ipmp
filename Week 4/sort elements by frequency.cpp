#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={2, 5, 2, 8, 5, 6, 8, 8};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    
    int j=0;
    int a[n][2];
    for(int i=0;i<n;i++)
    {
        a[i][0]=0;
        a[i][1]=1;
    }
    
    for(int i=0;i<n;i++,j++)
    {
        a[j][0]=i;
        while(arr[i+1]==arr[i])
        {
            i++;
            a[j][1]++;
        }
    }
    
    for (int i = 0; i < j; i++)
    for (int k = 0; k < j-i-1; k++)
        if (a[k][1] > a[k+1][1]){
            
            int temp=a[k][0];
            a[k][0]=a[k+1][0];
            a[k+1][0]=temp;
            
            temp=a[k][1];
            a[k][1]=a[k+1][1];
            a[k+1][1]=temp;
        }

    for(int i=j-1;i>=0;i--)
    {
        while(a[i][1]>0){
        cout<<arr[a[i][0]]<<endl;
        a[i][1]--;}
    }
}
