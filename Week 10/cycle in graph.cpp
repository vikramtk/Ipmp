#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>*v,int x,int y)
{
    v[x].push_back(y);
}

int cycle(vector<int>*adj,int i,int visited[],int recStack[])
{
    if(visited[i]==0)
    {
        visited[i]=1;
        recStack[i]=1;
        
        for(auto x:adj[i])
        {
            if(!visited[x] && cycle(adj,x,visited,recStack))
            return 1;
            
            else if(recStack[x])
            return 1;
        }
    }
    recStack[i]=0;
    return 0;
}

int iscyclic(vector<int>*adj,int n)
{
    int visited[n]={0},recStack[n]={0};
    
    for(int i=0;i<n;i++)
    if(cycle(adj,i,visited,recStack))
    return 1;
    
    return 0;
}

int main()
{
    int v=4;
    vector<int> adj[v];
    
    addedge(adj,0,1);
    addedge(adj,2,0);
    addedge(adj,1,3);
    
    cout<<iscyclic(adj,v);
}
