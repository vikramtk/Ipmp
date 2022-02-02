#include<bits/stdc++.h>
using namespace std;

void inplacetransform(int arr[],int r,int c)
{
    int size=r*c-1;
    int i=0;
    int t,cyclebegin,next;
    
    bitset<128> b;
    
    b.reset();
    b[0]=b[size]=1;
    
    while(i<size)
    {
        cyclebegin=i;
        t=arr[i];
        
        do{
            next=(i*r)%size;
            swap(arr[next],t);
            b[i]=1;
            i=next;
        }while(i!=cyclebegin);
        
        for(i=1;i<size && b[i];i++);
    }
}

void printarr(int arr[],int r,int c)
{
    int i=0;
    for(int j=0;j<r;j++)
    {
        for(int k=0;k<c;k++)
        {
            cout<<arr[i++]<<'\t';
        }
        cout<<endl;
    }
}

int main()
{
    int r=4,c=5;
    int size=r*c;
    int *arr = new int[size]; 
    
    for(int i=0;i<size;i++)
    arr[i]=i+1;
    
    printarr(arr,r,c);
    inplacetransform(arr,r,c);
    printarr(arr,c,r);
    
    return 0;
}
