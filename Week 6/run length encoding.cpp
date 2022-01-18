#include<bits/stdc++.h>
using namespace std;

void runlengthencoding(string str)
{
    int a=0;
    string s;
    for(int i=0;i<str.size();)
    {
        char m=str[i];
        int count=0;
        s[a++]=str[i];
        while(str[i]==m)
        {
            count++;
            i++;
        }
        s[a++]=count+48;
    }
    
    for(int i=0;i<a;i++)
    cout<<s[i];
}

int main()
{
    string s="gggggsshhhssiinnaaammmmm";
    runlengthencoding(s);
}
