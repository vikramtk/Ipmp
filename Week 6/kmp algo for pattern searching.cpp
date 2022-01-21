#include<bits/stdc++.h>
using namespace std;

void computelps(int*lps,int m,char*pat)
{
    int len=0,i=1;
    lps[0]=0;
    
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            len=lps[len-1];
            
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmp(char*pat,char*txt)
{
    int n=strlen(txt);
    int m=strlen(pat);
    
    int lps[m];
    computelps(lps,m,pat);
    
    int i=0,j=0;
    
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            i++;j++;
        }
        
        if(j==m)
        {
            cout<<"Pattern found at "<<i-j;
            j=lps[j-1];
        }
        
        else if(j<n && txt[i]!=pat[j])
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;
        }
    }
}

int main()
{
    char txt[] = "AAAAABAAAA";
    char pat[] = "AAAA";
    kmp(pat,txt);
}
