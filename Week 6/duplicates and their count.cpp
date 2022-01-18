#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="hdgdkshfmrnsgskgfhd";
    int count[256];
    
    for(int i=0;i<256;i++)
    count[i]=0;
    
    for(int i=0;i<s.size();i++)
    count[s[i]]++;
    
    for(int i=0;i<s.size();i++)
    {
        if(count[s[i]]>1)
        {
            cout<<s[i]<<'\t'<<count[s[i]];
            count[s[i]]=0;
        }
    }
}
