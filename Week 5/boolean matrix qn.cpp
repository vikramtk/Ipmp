#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r=3,c=4;
    int arr[3][4] = { {1, 0, 0, 1},
                       {0, 0, 1, 0},
                       {0, 0, 0, 0}};
                       
    int row=0,col=0;
    
    for(int i=0;i<r;i++)
    col=col | arr[i][0];
    
    for(int i=0;i<c;i++)
    row=row | arr[0][i];
    
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            arr[i][0]=arr[i][0] | arr[i][j];
            arr[0][j]=arr[0][j] | arr[i][j];
        }
    }
    
    for(int i=1;i<r;i++)
    for(int j=1;j<c;j++)
    arr[i][j]=arr[0][j] | arr[i][0];
    
    for(int i=1;i<r;i++)
    arr[i][0]=col;
    
    for(int i=1;i<c;i++)
    arr[0][i]=row;
    
    arr[0][0]=row | col;
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<'\t';
        }
        cout<<endl;
    }
}
