//We could create a copy of original graph in case we need that for other purposes,here i have modified it

#include<bits/stdc++.h>
using namespace std;

#define v 4

void allpairs(int dist[v][v])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            for(int k=0;k<v;k++)
            {
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][j]>dist[i][k]+dist[k][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    
    for(int i=0;i<v;i++)
    dist[i][i]=0;
    
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int graph[v][v]={{INT_MAX,5,INT_MAX,10},
                    {INT_MAX,INT_MAX,3,INT_MAX},
                    {INT_MAX,INT_MAX,INT_MAX,1},
                    {INT_MAX,INT_MAX,INT_MAX,INT_MAX},    
    };
 
    allpairs(graph);
 
    return 0;
}
