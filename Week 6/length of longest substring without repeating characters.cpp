#include<bits/stdc++.h>
using namespace std;

int window(string s)
{
    int res=0,i=0;
    int lastindex[256]={-1};
    
    for(int j=0;j<s.size();j++)
    {
        i=max(i,lastindex[s[j]]+1);
        res=max(res,j-i+1);
        lastindex[s[j]]=j;
    }
    
    return res;
}

int main()
{
    string s="GEEKSFORGEEKS";
    cout<<window(s);
}
