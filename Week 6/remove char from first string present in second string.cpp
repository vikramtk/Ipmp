#include<bits/stdc++.h>
using namespace std;

void removechar(string s1,string s2)
{
    bool count[256];
    for(int i=0;i<256;i++)
    count[i]=0;
    
    for(int i=0;i<s2.size();i++)
    if(count[s2[i]]==0)
    count[s2[i]]=1;
    
    string s3;
    int k=0;
    for(int j=0;j<s1.size();j++)
    {
        if(count[s1[j]])
        continue;
        else
        {
            s3[k]=s1[j];
            k++;
        }
    }
    
    for(int i=0;i<k;i++)
    cout<<s3[i];
}

int main()
{
    string s1="absgsjahsbrtshan";
    string s2="ash";
    
    removechar(s1,s2);
}
