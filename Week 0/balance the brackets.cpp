#include <bits/stdc++.h>
using namespace std;

int balanced(string s)
{
    stack<char>st;
    char c;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        st.push(s[i]);
        
        else if(st.empty())
        return 0;
        
        else{
        c=st.top();
        st.pop();
        
        if(s[i]==')')
        {
            if(c=='(')
            continue;
            else return 0;
        }
        
        if(s[i]==']')
        {
            if(c=='[')
            continue;
            else return 0;
        }
        
        if(s[i]=='}')
        {
            if(c=='{')
            continue;
            else return 0;
        }
        }
    }
    if(st.empty())
    return 1;
    else
    return 0;
}

int main()
{
    string expr="{[()]{}}";
    
    string expr2="(([)])";
    
    if(balanced(expr))
    cout<<"Expr balanced";
    else
    cout<<"Expr not balanced";
    
    if(balanced(expr2))
    cout<<"\nExpr2 balanced";
    else
    cout<<"\nExpr2 not balanced";
    
    return 0;
}
