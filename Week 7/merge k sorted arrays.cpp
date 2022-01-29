#include<bits/stdc++.h>
#include "heap.h"
using namespace std;

int main()
{
    minheap m(10);
    int i,k=3,n=4;
    int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    
    int visited[k];
    for(int i=0;i<k;i++)
    visited[i]=0;
    
    for(i=0;i<k;i++)
    m.insert(arr[i][0]);
    
    while(m.heapsize>0)
    {
        for(i=0;i<k;i++)
        {
            if(visited[i]>n-1)
            continue;
            if(arr[i][visited[i]]==m.peek()){
            break;
            }
        }
        
        visited[i]++;
        if(visited[i]<=n-1)
        m.insert(arr[i][visited[i]]);
        cout<<m.extractmin()<<endl;
    }
    return 0;
}
