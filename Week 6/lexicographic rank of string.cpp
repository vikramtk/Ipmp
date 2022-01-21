#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n<=1)
    return 1;
    
    else return n*factorial(n-1);
}

int lex(string s)
{
    int mul=factorial(s.length());
    int rank=1;
    
    int count[256];
    for(int i=0;i<256;i++)
    count[i]=0;
    
    for(int i=0;i<s.length();i++)
    count[s[i]]++;
    
    for(int i=1;i<256;i++)
    count[i]+=count[i-1];
    
    for(int i=0;i<s.length();i++)
    {
        mul/=(s.length()-i);
        
        rank+=(count[s[i]-1]*mul);
        
        for(int j=s[i];j<256;j++)
        count[j]--;
    }
    
    return rank;
}

int main()
{
    string s="string";
    cout<<lex(s);
}
