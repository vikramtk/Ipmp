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

class subset{
    public:
        int rank,parent;
};

graph* creategraph(int v,int e)
{
    graph *g=new graph();
    g->v=v;
    g->e=e;
    
    g->edges=new edge[(g->e)*sizeof(edge)];
    
    return g;
}

int find(subset *subsets,int i)
{
    if(subsets[i].parent!=i)
    subsets[i].parent=find(subsets,subsets[i].parent);
    
    return subsets[i].parent;
}

int iscycle(graph *g)
{
    struct subset*subsets=(struct subset*)malloc((g->v)*sizeof(struct subset));
    
    for(int i=0;i<g->v;i++)
    {
        subsets[i].rank=0;
        subsets[i].parent=i;
    }
    
    for(int e=0;e<g->e;e++)
    {
        int x=find(subsets,g->edges[e].src);
        int y=find(subsets,g->edges[e].dest);
        
        if(x==y)
        return 1;
        
        if(subsets[x].rank>subsets[y].rank)
        subsets[y].parent=x;
        else if(subsets[x].rank<subsets[y].rank)
        subsets[x].parent=y;
    
        else
        {
            subsets[y].parent=x;
            subsets[x].rank++;
        }
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
