#include<bits/stdc++.h>
using namespace std;

void printreverse(char str[],int i)
{
    if(i==0)
    return;
    
    else
    printreverse(str+1,i-1);
    
    printf("%c",*str);
}

int main()
{
    char str[]="markiv";
    printreverse(str,sizeof(str));
}
