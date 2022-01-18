#include<bits/stdc++.h>
using namespace std;

int stringcompare(string s1,string s2)
{
    for(int j=0;j<s1.size();j++)
    s1[j]=toupper(s1[j]);
    
    for(int j=0;j<s2.size();j++)
    s2[j]=toupper(s2[j]);
    
    int i=0;
    
    while(i<s1.size() && i<s2.size())
    {
        if(s1[i]>s2[i])
        return 1;
        
        else if(s1[i]<s2[i])
        return -1;
        
        i++;
    }
    
    if(s1.size()==s2.size())
    return 0;
    
    if(s1.size()>s2.size())
    return 1;
    
    else return -1;
}

int main()
{
    string s1="GEEKS";
    string s2="for";
    string s3="abc";
    string s4="geeks";
    
    cout<<stringcompare(s1,s2);
    cout<<stringcompare(s1,s3);
    cout<<stringcompare(s1,s4);
    cout<<stringcompare(s3,s2);
}
