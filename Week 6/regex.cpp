#include<bits/stdc++.h>
using namespace std;

bool canmatch(char a,char b)
{
    return (a==b || b=='.');
}

bool ismatch(const char*s,const char* p)
{
    int ls=strlen(s),lp=strlen(p);
    
    vector<vector<bool>> F(ls+1,vector<bool>(lp+1));
    F[0][0]=1;
    
    for(int i=0;i<=ls;i++)
    {
        for(int j=1;j<=lp;j++)
        {
            if(i>0)
            if(F[i-1][j-1] && canmatch(s[i-1],p[j-1]))
            {
                F[i][j]=1;
                continue;
            }
            
            if(i>0 && j>1)
            if(F[i-1][j] && canmatch(s[i-1],p[j-2]) && p[j-1]=='*')
            {
                F[i][j]=1;
                continue;
            }
            
            if(j>1)
            if(F[i][j-2] && p[j-1]=='*')
            {
                F[i][j]=1;
                continue;
            }
        }
    }
    
    for(int i=0;i<=ls;i++)
    {
        for(int j=0;j<=lp;j++)
        {
            cout<<F[i][j]<<'\t';
        }
        cout<<endl;
    }
    
    return F[ls][lp];
}

int main()
{
    const char s[]="aaabbbbc";
    const char p[]="a*b*c*";
    
    cout<<ismatch(s,p);
    return 0;
}
