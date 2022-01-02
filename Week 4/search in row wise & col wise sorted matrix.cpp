#include<bits/stdc++.h>
using namespace std;

int main()
{
     int arr[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
                      
    int row=-1,column=-1,x=29,n=4,found=-1;
    
    if(arr[0][0]==x){
    cout<<"0,0";
    found=0;}
    
    for(int c=1;c<n;c++)
    {
        if(arr[c][c]==x){
        cout<<c<<","<<c;
        found=0;}
        
        if(arr[c][c]>x && arr[c-1][c-1]<x)
        row=column=c;
    }
    
    if(row>=0 && column>=0)
    {
        for(int i=column;i<n;i++)
        {
            if(arr[i][column-1]==x){
            cout<<i<<","<<column-1;
            found=0;}
        }
        
        for(int i=row;i<n;i++)
        {
            if(arr[row-1][i]==x){
            cout<<row-1<<","<<i;
            found=0;}
        }
    }
    
    if(found!=0)
    cout<<"Not found";
}
