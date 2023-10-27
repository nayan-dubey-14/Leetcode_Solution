class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int minSum=INT_MAX;
        int sum=0;
        for(int i=0;i<=nums.size()-3;i++)
        {
            sum+=nums[i];
            
            for(int j=i+1;j<=nums.size()-2;j++)
            {
                
                if(!(nums[j]>nums[i])) continue;
                sum+=nums[j];

                for(int k=j+1;k<nums.size();k++)
                {
                    if(!(nums[j]>nums[k])) continue;
                    sum+=nums[k];
                    minSum=min(minSum,sum);
                    sum-=nums[k];
                }
                sum-=nums[j];
            }
            sum-=nums[i];

        }
        if(minSum==INT_MAX) return -1;
        return minSum;
        
    }
};