class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        int ltor[n],rtol[n];
        int temp=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
                temp=i;
            ltor[i]=temp;
        }
        temp=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==key)
                temp=i;
            rtol[i]=temp;
        }
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(abs(i-ltor[i])<=k && ltor[i]!=-1 || abs(i-rtol[i])<=k && rtol[i]!=-1)
                v.push_back(i);
        }
        return v;
    }
};
