#include<bits/stdc++.h>
using namespace std;

int main()
{
    int index[256],minimum=999999;
    for(int i=0;i<256;i++)
    index[i]=-1;
    
    string str="GeeksforGeeks";
    
    for(int i=0;i<str.size();i++){
    if(index[str[i]]==-1)
    index[str[i]]=i;
    else
    index[str[i]]=-2;
    }
    
    for(int i=0;i<256;i++)
    {
        if(index[i]>=0)
        minimum=min(minimum,index[i]);
    }
    
    cout<<str[minimum];
}
