//Here it takes O(v2) time....it can be optimised to O(E) by representing only edges using adjacency list
//similar to the one in which we represent graph using vector<int> adj[v]

#include<bits/stdc++.h>
using namespace std;

#define v 4

void addedge(int adj[v][v],int x,int y)
{
    if(x<y)       //making the edge from small to large node
    adj[x][y]=1;
    
    else
    adj[y][x]=1;
}

int iscycle(int adj[v][v])
{
    int included[v]={0};
    
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(adj[i][j])
            {
            if(included[i]==1 && included[j]==1)
            return 1;
            
            included[i]=1;
            included[j]=1;
            }
        }
    }
    
    return 0;
}

int main()
{
    int adj[v][v];
    
    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    adj[i][j]=0;
    
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,0);
    addedge(adj,2,3);
    
    cout<<iscycle(adj);
}
