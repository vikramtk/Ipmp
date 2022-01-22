#include<bits/stdc++.h>
using namespace std;

char* removedup(char* s,char* lastremoved)
{
    if(s[0]=='\0' || s[1]=='\0')
    return s;
    
    if(s[0]==s[1])
    {
        *lastremoved=s[0];
        while(s[1]&&s[1]==s[0])
        s++;
        s++;
        return removedup(s,lastremoved);
    }
    
    char*remstr=removedup(s+1,lastremoved);
    
    if(remstr[0]&&remstr[0]==s[0])
    {
        *lastremoved=s[0];
        return remstr+1;
    }
    
    if(remstr[0]=='\0' && *lastremoved==s[0])
    {
        return remstr;
    }
    
    remstr--;
    remstr[0]=s[0];
    return remstr;
}

int main()
{
    char s[]="azxxxzay";
    char lastremoved='\0';
    cout<<removedup(s,&lastremoved);
}
