#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>*v,int x,int y)
{
    v[x].push_back(y);
}

void print(vector<int>*v,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"List of vertex "<<i<<endl;
        cout<<"head";
        for(auto x:v[i])
        cout<<"->"<<x;
        cout<<endl;
    }
}

void dfs(vector<int>*adj,int n,int start)
{
    int flag,count=0,visited[n]={0};
    
    stack<int>s;
    
    s.push(start);
    
    while(count<n){
        int t=s.top();
        
        if(visited[t])
        {
            s.pop();
            continue;
        }
        
        cout<<t;
        count++;
        visited[t]=1;
        
        for(auto x:adj[t])
        {
            if(!visited[x])
            {
                s.push(x);
            }
        }
    }
}

int main()
{
    int v=4;
    vector<int> adj[v];
    
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,2,0);
    addedge(adj,1,3);
    addedge(adj,3,3);
    
    print(adj,v);
    
    dfs(adj,v,2);
}
