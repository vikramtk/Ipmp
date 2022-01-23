#include<bits/stdc++.h>
using namespace std;

string window(string s,string t)
{
    int m[256]={0};
    
    int ans=INT_MAX,start=0,count=0;
    
    for(int i=0;i<t.length();i++)
    {
        if(m[t[i]]==0)
        count++;
        m[t[i]]++;
    }
    
    int i=0,j=0;
    
    while(j<s.length())
    {
        m[s[j]]--;
        if(m[s[j]]==0)
        count--;
        
        if(count==0)
        {
            while(count==0)
            {
                if(ans > j-i+1)
                {
                    ans=j-i+1;
                    start=i;
                }
                
                m[s[i]]++;
                if(m[s[i]]>0)
                count++;
                i++;
            }
        }
        j++;
    }
    
    if(ans<INT_MAX)
    return s.substr(start,ans);
    else
    return "-1";
}

int main()
{
    string s="this is a test string";
    string t="tist";
    
    cout<<window(s,t);
}
