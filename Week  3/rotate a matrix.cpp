#include<bits/stdc++.h>
using namespace std;
#define n 5

void rotate(int arr[5][5])
{
    int temp;
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[j][n-i-1];
            arr[j][n-i-1]=arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j]=arr[n-1-j][i];
            arr[n-1-j][i]=temp;
        }
    }
}

int main()
{
    int a[5][5],c=0;;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        a[i][j]=c;
        c++;
    }
    
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    
    rotate(a);
    cout<<"\n\n";
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout<<a[i][j]<<'\t';
        cout<<endl;
    }
    
    return 0;
}
