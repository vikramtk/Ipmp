#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1="listen";
    string s2="silent";
    
    int c1[256],c2[256];
    
    for(int i=0;i<256;i++)
    c1[i]=c2[i]=0;
    
    for(int i=0;i<s1.size();i++)
    c1[i]++;
    
    for(int i=0;i<s2.size();i++)
    c2[i]++;
    
    for(int i=0;i<256;i++)
    {
        if(c1[i]!=c2[i])
        {
            cout<<"Not an anagram";
            exit(0);
        }
    }
    
    cout<<"anagrams";
}
