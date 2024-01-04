class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        map<int,int> m;
        for(int i:nums) m[i]++;
        for(auto itr:m)
        {
            if(itr.second==1) return -1;
            else if(itr.second==2) count++;
            else
            {
                count+=ceil((float)itr.second/3);
            }
        }
        return count;
        
    }
};