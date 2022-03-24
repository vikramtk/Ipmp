#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> *adj,int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool isbipartite(vector<int>* adj,int v)
{
    vector<int> col(v,-1);
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<v;i++)
    {
        if(col[i]==-1)
        {
            q.push({i,0});
            col[i]=0;
            
            while(!q.empty())
            {
                pair<int,int> p=q.front();
                q.pop();
                
                int ver=p.first;
                int c=p.second;
                
                for(int x:adj[ver])
                {
                    if(col[x]==c)
                    return 0;
                    
                    else if(col[x]==-1){
                    col[x]=(c)?0:1;
                    q.push({x,col[x]});
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int v=7;
    vector<int> adj[v];

    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,5,4);
    addedge(adj,5,6);

    cout<<isbipartite(adj,v);

    return 0;
}
