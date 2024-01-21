class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long maxSum=0;
        long long sum=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<=sum)
            {
                sum+=nums[i];
            }
            else
            {
                maxSum=max(sum,maxSum);
                sum=nums[i];
            }
        }
        maxSum=max(sum,maxSum);
        return maxSum;
    }
};