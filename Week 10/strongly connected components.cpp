#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    
    list<int> *adj;
    
    void fill(int v,bool visited[],stack<int>&s);
    void dfs(int v,bool visited[]);
    
    public:
    graph(int V);
    void addedge(int a,int b);
    
    void scc();
    graph transpose();
};

graph::graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}

void graph::dfs(int v,bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    if(!visited[*i])
    dfs(*i,visited);
}

graph graph::transpose()
{
    graph g(V);
    for(int v=0;v<V;v++)
    {
        list<int>::iterator i;
        
        for(i=adj[v].begin();i!=adj[v].end();i++)
        g.adj[*i].push_back(v);
    }
    return g;
}

void graph::addedge(int a,int b)
{
    adj[a].push_back(b);
}

void graph::fill(int v,bool visited[],stack<int>&s)
{
    visited[v]=true;
    
    list<int>::iterator i;
    
    for(i=adj[v].begin();i!=adj[v].end();i++)
    if(!visited[*i])
    fill(*i,visited,s);
    
    s.push(v);
}

void graph::scc()
{
    stack<int>s;
    
    bool*visited=new bool[V];
    
    for(int i=0;i<V;i++)
    visited[i]=false;
    
    for(int i=0;i<V;i++)
    if(visited[i]==false)
    fill(i,visited,s);
    
    graph gr=transpose();
    
    for(int i=0;i<V;i++)
    visited[i]=false;
    
    while(s.empty()==false)
    {
        int v=s.top();
        s.pop();
        
        if(visited[v]==false)
        {
            gr.dfs(v,visited);
            cout<<endl;
        }
    }
}

int main()
{
    graph g(5);
    
    g.addedge(1,0);
    g.addedge(0,2);
    g.addedge(2,1);
    g.addedge(0,3);
    g.addedge(3,4);
    
    g.scc();
    
    return 0;
}
