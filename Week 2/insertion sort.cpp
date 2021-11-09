#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        if(arr[j]>arr[i])
        {
            temp=arr[i];
            while(arr[j]>temp && j>=0)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
        cout<<"\nIteration "<<i<<endl;
        for(int j=0;j<n;j++)
        cout<<arr[j]<<'\t';
    }
}

int main()
{
    int arr[]={4,5,7,2,3,1,8,0,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array\n";
    for(int j=0;j<size;j++)
    cout<<arr[j]<<'\t';
    insertionsort(arr,size);
    return 0;
}
