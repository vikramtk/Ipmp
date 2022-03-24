#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> *adj,int x,int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void color(vector<int>* adj,int v)
{
    int coloring[v]={-1};
    
    int i=0;
    coloring[0]=0;
    
    for(int i=1;i<v;i++)
    {
        int temp[v]={-1};
        for(auto x:adj[i])
        {
            if(coloring[x]==-1)
            continue;
            
            else
            temp[coloring[x]]=1;
        }
        
        for(int j=0;j<v;j++){
        if(temp[j]==1)
        continue;
        else{
        coloring[i]=j;
        break;
        }
        }
    }
    
    for(int i=0;i<v;i++)
    cout<<coloring[i]<<endl;
}

int main() {
    int v=5;
    vector<int> adj[v];

    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,2,1);
    addedge(adj,4,1);
    addedge(adj,2,4);
    addedge(adj,3,4);

    color(adj,v);

    return 0;
}
