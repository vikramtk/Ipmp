#include<bits/stdc++.h>
using namespace std;

#define n 4

void stable(int mp[n][n],int wp[n][n])
{
    
    int i,j,count=0;
    
    int man[n];
    memset(man,-1,sizeof(man));
    
    int woman[n];
    memset(woman,-1,sizeof(woman));
    
    int propose[n][n];
    memset(propose,-1,sizeof(propose));
    
    while(count<n)
    {
        for(i=0;i<n;i++)
        if(man[i]==-1)
        break;
        
        for(j=0;j<n;j++)
        {
            int w=mp[i][j];
            
            if(propose[i][w]==-1)
            {
                if(woman[w]==-1)
                {
                woman[w]=i;
                propose[i][w]=1;
                man[i]=1;
                count++;
                break;
                }
                
                else
                {
                    int otherman=woman[w];
                    
                    for(int k=0;k<n;k++)
                    {
                        if(wp[w][k]!=i && wp[w][k]!=otherman)
                        continue;
                        
                        else if(wp[w][k]==i)
                        {
                            woman[w]=i;
                            man[otherman]=-1;
                            propose[i][w]=1;
                            man[i]=1;
                            break;
                        }
                        
                        else
                        {
                            propose[i][w]=1;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    cout<<i<<" "<<woman[i]<<endl;
}

int main()
{
    int manprefer[n][n] = { {3, 1, 2, 0},
        {1, 0, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    
    
    int womanprefer[n][n] = { {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    
    stable(manprefer,womanprefer);
    
    return 0;
}
