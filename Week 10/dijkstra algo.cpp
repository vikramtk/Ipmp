#include<bits/stdc++.h>
using namespace std;

#define V 9

int mindist(int dist[],bool spt[])
{
    int min=INT_MAX;
    int index;
    
    for(int i=0;i<V;i++)
    if(!spt[i]&&dist[i]<=min)
    {
        min=dist[i];
        index=i;
    }
    
    return index;
}

void dijkstra(int graph[V][V],int start)
{
    int dist[V];
    bool spt[V];
    
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        spt[i]=false;
    }
    
    dist[start]=0;
    
    for(int count=0;count<V-1;count++)
    {
        int u=mindist(dist,spt);
        
        spt[u]=1;
        
        for(int v=0;v<V;v++)
        if(!spt[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[v]>dist[u]+graph[u][v])
        dist[v]=dist[u]+graph[u][v];
    }
    
    for(int i=0;i<V;i++)
    cout<<i<<"\t"<<dist[i]<<endl;
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
}
