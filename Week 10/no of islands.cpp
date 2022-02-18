#include<bits/stdc++.h>
using namespace std;

#define r 5
#define c 5

int issafe(int M[][c],int row,int col,int visited[][c])
{
    return M[row][col] && row<r && row>=0 && col<c && col>=0 && !visited[row][col];
}

void dfs(int M[][c],int row,int col,int visited[][c])
{
    int rowno[]={-1,-1,-1,0,0,1,1,1};
    int colno[]={-1,0,1,-1,1,-1,0,1};
    
    visited[row][col]=1;
    for(int i=0;i<8;i++)
    {
        if(issafe(M,row+rowno[i],col+colno[i],visited))
        dfs(M,row+rowno[i],col+colno[i],visited);
    }
}

int islands(int M[][c])
{
    int count=0;
    
    int visited[r][c];
    
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    visited[i][j]=0;
    
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    if(M[i][j] && !visited[i][j]){
    dfs(M,i,j,visited);
    count++;}
    
    return count;
}

int main()
{
    int M[][c] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
    
    cout<<islands(M);
}
