#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high)
{
    int j,temp,i=low-1,pivot=arr[high];
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    return (i+1);
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main()
{
    int arr[]={4,6,2,3,1,7,9,0,8,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    
    for(int i=0;i<size;i++)
        cout<<arr[i]<<'\t';
}
