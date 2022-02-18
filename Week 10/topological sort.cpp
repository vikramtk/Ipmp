#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>*v,int x,int y)
{
    v[x].push_back(y);
}

int main()
{
    int v=6;
    vector<int> adj[v];
    
    addedge(adj,2,3);
    addedge(adj,3,1);
    addedge(adj,4,0);
    addedge(adj,4,1);
    addedge(adj,5,0);
    addedge(adj,5,2);
    
    int indegree[v]={0},visited[v]={0};
    
    for(int i=0;i<v;i++)
    for(auto x:adj[i])
    {
        indegree[x]++;
    }
    
    for(int i=0;i<v;i++)
    {
        int min=99999,minpos=-1;
        
        for(int j=0;j<v;j++)
        {
            if(!visited[j] && indegree[j]<min)
            {
                min=indegree[j];
                minpos=j;
            }
        }
        
        cout<<minpos;
        visited[minpos]=1;
        
        for(auto x:adj[minpos])
        indegree[x]--;
    }
}
