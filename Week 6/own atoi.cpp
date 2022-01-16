#include <bits/stdc++.h>
using namespace std;

int atoi1(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]-48 >=0 && str[i]-48<10)
        continue;
        
        else
        return 0;
    }
    int num=0;
    for(int i=0;i<str.size();i++)
    {
        num+=pow(10,str.size()-i-1)*(str[i]-48);
    }
    return num;
}

int main()
{
    int val;
    char strn1[] = "12546";

    val = atoi1(strn1);
    cout <<"String value = " << strn1 << endl;
    cout <<"Integer value = " << val << endl;

    char strn2[] = "GeeksforGeeks";
    val = atoi1(strn2);
    cout <<"String value = " << strn2 << endl;
    cout <<"Integer value = " << val <<endl;

    return (0);
}
