#include<bits/stdc++.h>
using namespace std;

#define m 6
#define n 6

bool bpm(int graph[m][n],bool seen[],int i,int arr[])
{
    for(int j=0;j<n;j++)
    {
        if(graph[i][j] && !seen[j])
        {
            seen[j]=true;
            
            if(arr[j]<0 || bpm(graph,seen,arr[j],arr)){
                arr[j]=i;
            return true;
            }
        }
    }
    
    return false;
}

int maxbp(int graph[m][n])
{
    int arr[n];
    memset(arr,-1,sizeof(arr));
    
    int result=0;
    
    for(int i=0;i<m;i++)
    {
        bool seen[n];
        memset(seen,0,sizeof(seen));
    
        if(bpm(graph,seen,i,arr))
        result++;
    }
    
    return result;
}

int main()
{
    int graph[m][n] =   {{0, 1, 1, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1}};
                          
    cout<<maxbp(graph);
}
