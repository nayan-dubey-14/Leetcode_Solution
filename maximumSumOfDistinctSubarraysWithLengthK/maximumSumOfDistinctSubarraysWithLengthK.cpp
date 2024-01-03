class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        long long sum=0;
        long long maxSum=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            m[nums[i]]++;
            if((i-j+1)==k)
            {
                if(m.size()==k) maxSum=max(maxSum,sum);
            }
            else if((i-j+1)>k)
            {
                sum-=nums[j];
                m[nums[j]]--;
                if(m[nums[j]]==0) m.erase(nums[j]);
                if(m.size()==k) maxSum=max(maxSum,sum);
                j++;
            }
            
        }
        return maxSum;
    }

};