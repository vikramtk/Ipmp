#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][4] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
                    
    int ans;
    
    int j=4-1;
    for(int i=0;i<4;i++)
    {
        int flag=0;
        
        while(j>=0 && arr[i][j]==1){
        j-=1;
        flag=1;
        }
        
        if(flag)
        ans=i;
    }
    
    cout<<ans;
}
