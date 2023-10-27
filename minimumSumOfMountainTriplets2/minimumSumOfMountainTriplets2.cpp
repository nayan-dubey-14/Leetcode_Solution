class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> prevMin(nums.size(),0);
        vector<int> nextMin(nums.size(),0);
        int min=nums[0];
        int result=INT_MAX;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            if(nums[i]>min) prevMin[i]=min;
            else
            {
                prevMin[i]=0;
                min=nums[i];
            }
        }
        min=nums[size-1];
        for(int i=size-1;i>=0;i--)
        {
            if(nums[i]>min) nextMin[i]=min;
            else
            {
                nextMin[i]=0;
                min=nums[i];
            }
        }
        for(int i=0;i<size;i++)
        {
            if(prevMin[i]==0 || nextMin[i]==0) continue;
            int sum=nums[i]+prevMin[i]+nextMin[i];
            if(result>sum) result=sum;
        }
        if(result==INT_MAX) return -1;
        return result;
        
    }
};