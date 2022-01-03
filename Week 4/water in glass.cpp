#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=4,j=2;
    float x=7.0;
    
    if(j>i)
    {
        cout<<"Invalid";
        exit(0);
    }
    
    float glass[i*(i+1)/2];
    int index=0;
    
    memset(glass,0,sizeof(glass));
    glass[index]=x;
    
    for(int row=1;row<=i;row++)
    {
        for(int column=1;column<=row;column++,index++)
        {
            x=glass[index];
            
            if(x>1.0)
            glass[index]=1.0;
            else
            glass[index]=x;
            
            if(x>=1.0)
            x-=1;
            else
            x=0.0;
            
            glass[index+row]+=x/2;
            glass[index+row+1]+=x/2;
        }
    }
    
    cout<<glass[(i*(i-1)/2)+j-1];
}
