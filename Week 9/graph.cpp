#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>*v,int x,int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
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

int main()
{
    int v=5;
    vector<int> adj[v];
    
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,2,4);
    addedge(adj,3,4);
    
    print(adj,v);
}
