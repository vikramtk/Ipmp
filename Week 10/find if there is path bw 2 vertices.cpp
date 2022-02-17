#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>*v,int x,int y)
{
    v[x].push_back(y);
}

int bfs(vector<int>*adj,int n,int start,int end)
{
    int flag,count=0,visited[n]={0};
    
    queue<int>s;
    
    s.push(start);
    
    while(count<n && s.size()!=0){
        int t=s.front();
    
        if(visited[t])
        {
            s.pop();
            continue;
        }
        
        if(t==end)
        {
            return 1;
        }
        
        visited[t]=1;
        
        for(auto x:adj[t])
        {
            if(!visited[x])
            {
                s.push(x);
            }
        }
    }
    return 0;
}

int main()
{
    int v=4;
    vector<int> adj[v];
    
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,2,0);
    addedge(adj,2,3);
    addedge(adj,3,3);
        
    cout<<bfs(adj,v,3,2);
}
