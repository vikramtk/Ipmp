class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int count=0;
        int temp[n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                temp[i][j]=0;
        
        for(int i=0;i<dig.size();i++)
        {
            temp[dig[i][0]][dig[i][1]]=1;
        }
        
        for(int i=0;i<artifacts.size();i++)
        {
            if(artifacts[i][0]==artifacts[i][2])
            {
                int flag=0;
                
                for(int j=artifacts[i][1];j<=artifacts[i][3];j++)
                    if(temp[artifacts[i][0]][j]==0)
                        flag=1;
                
                if(flag==0)
                    count++;
            }
            
            else if(artifacts[i][1]==artifacts[i][3])
            {
                int flag=0;
                
                for(int j=artifacts[i][0];j<=artifacts[i][2];j++)
                    if(temp[j][artifacts[i][1]]==0)
                        flag=1;
                
                if(flag==0)
                    count++;
            }
            
            else
            {
                if(temp[artifacts[i][0]][artifacts[i][1]]==1&&
                   temp[artifacts[i][0]][artifacts[i][3]]==1&&
                  temp[artifacts[i][2]][artifacts[i][1]]==1&&
                  temp[artifacts[i][2]][artifacts[i][3]]==1)
                    count++;
            }
        }
        
        return count;
    }
};
