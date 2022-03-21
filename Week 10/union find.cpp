#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int src,dest;
};

class graph{
    public:
        int v,e;
        edge*edges;
};

graph* creategraph(int v,int e)
{
    graph *g=new graph();
    g->v=v;
    g->e=e;
    
    g->edges=new edge[(g->e)*sizeof(edge)];
    
    return g;
}

int find(int parent[],int i)
{
    if(parent[i]==-1)
    return i;
    
    else
    return find(parent,parent[i]);
}

int iscycle(graph *g)
{
    int parent[g->v];
    
    for(int i=0;i<g->v;i++)
    parent[i]=-1;
    
    for(int i=0;i<g->e;i++)
    {
        int x=find(parent,g->edges[i].src);
        int y=find(parent,g->edges[i].dest);
        
        if(x==y)
        return 1;
        
        parent[x]=y;   //union
    }
    
    return 0;
}

int main()
{
    int v=4,e=4;
    graph *g;
    g=creategraph(v,e);
    
    g->edges[0].src=0;
    g->edges[0].dest=1;
    
    g->edges[1].src=1;
    g->edges[1].dest=2;
    
    g->edges[2].src=2;
    g->edges[2].dest=3;
    
    g->edges[3].src=1;
    g->edges[3].dest=3;
    
    cout<<iscycle(g);
}
