#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX

int main()
{
    int v=6;
    
    int graph[v][v]={
        {0,1,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,1,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0},
    };
    
    int weight[v][v]={
        {0,5,3,0,0,0},
        {0,0,2,6,0,0},
        {0,0,0,7,4,0},
        {0,0,0,0,-1,7},
        {0,0,0,0,0,-2},
        {0,0,0,0,0,0},
    };
    
    int indegree[v]={0},visited[v]={0};
    int topo[v];
    
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            indegree[j]+=graph[i][j];
        }
    }
    
    int count=0;
    
    while(count<v)
    {
        int index=-1,min=999;
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i]&&indegree[i]<min){
            min=indegree[i];
            index=i;
            }
        }
        
        topo[count]=index;
        visited[index]=1;
        count++;
    }
    
    int dist[v],source=1;
    
    for(int i=0;i<v;i++)
    dist[i]=inf;
    
    dist[source]=0;
    
    for(int i=0;i<v;i++)
    {
        int u=topo[i];
        for(int j=0;j<v;j++)
        {
            if(graph[u][j] && dist[u]!=inf && dist[j]>dist[u]+weight[u][j])
            dist[j]=dist[u]+weight[u][j];
        }
    }
    
    for(int i=0;i<v;i++)
    cout<<dist[i]<<endl;
}
