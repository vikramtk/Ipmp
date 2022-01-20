#include<bits/stdc++.h>
using namespace std;

void reversewords(string s)
{
    char s2[s.length()];
    int i=0;
    
    for(int j=s.length()-1;j>=0;j--)
    {
        if(s[j]==' ')
        {
            for(int k=j+1;k<s.length() && s[k]!=' ';k++){
            s2[i]=s[k];
            i++;}
            
            s2[i]=' ';
        i++;
        }
        
        else if(j==0)
        {
         for(int k=j;k<s.length() && s[k]!=' ';k++){
            s2[i]=s[k];   
            i++;}
        }
    }
    
    for(int i=0;i<s.length();i++)
    cout<<s2[i];
}

int main()
{
    string s="i love programming very much";
    reversewords(s);
}
