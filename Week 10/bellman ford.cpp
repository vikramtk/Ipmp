#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src,dest,weight;
};

struct graph{
    int v,e;
    struct Edge* edge;
};

struct graph*create(int v,int e)
{
    struct graph*g=new graph;
    g->v=v;
    g->e=e;
    g->edge=new Edge[e];
    return g;
}

void bellmanford(struct graph*g,int src)
{
    int v=g->v;
    int e=g->e;
    int dist[v];
    
    for(int i=0;i<v;i++)
    dist[i]=INT_MAX;
    
    dist[src]=0;
    
    for(int i=0;i<v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(dist[g->edge[j].src]!=INT_MAX && dist[g->edge[j].src]+g->edge[j].weight<dist[g->edge[j].dest])
            dist[g->edge[j].dest]=dist[g->edge[j].src]+g->edge[j].weight;
        }
    }
    
    for(int j=0;j<e;j++)
    {
        if(dist[g->edge[j].src]!=INT_MAX && dist[g->edge[j].src]+g->edge[j].weight<dist[g->edge[j].dest])
        {
            cout<<"Graph contains negative weight cycle";
            return;
        }
    }
    
    for(int i=0;i<v;i++)
    cout<<dist[i]<<" ";
}

int main()
{
    int v=5,e=8;
    
    struct graph*g=create(v,e);
    
    g->edge[0].src = 0;
    g->edge[0].dest = 1;
    g->edge[0].weight = -1;
 
    g->edge[1].src = 0;
    g->edge[1].dest = 2;
    g->edge[1].weight = 4;
 
    g->edge[2].src = 1;
    g->edge[2].dest = 2;
    g->edge[2].weight = 3;
 
    g->edge[3].src = 1;
    g->edge[3].dest = 3;
    g->edge[3].weight = 2;
 
    g->edge[4].src = 1;
    g->edge[4].dest = 4;
    g->edge[4].weight = 2;
 
    g->edge[5].src = 3;
    g->edge[5].dest = 2;
    g->edge[5].weight = 5;
 
    g->edge[6].src = 3;
    g->edge[6].dest = 1;
    g->edge[6].weight = 1;
 
    g->edge[7].src = 4;
    g->edge[7].dest = 3;
    g->edge[7].weight = -3;
 
    bellmanford(g,0);
 
    return 0;
}
