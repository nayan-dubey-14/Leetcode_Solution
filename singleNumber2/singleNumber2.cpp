class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int countBits=0;
        int pow=1;
        int result=0;
        //calculating bit set
        for(int i=0;i<32;i++)
        {
            countBits=0;
            for(int j=0;j<nums.size();j++)
            {
                //checking for every bit
                countBits=countBits+(nums[j]&1);
                nums[j]=nums[j]>>1;
            }
            countBits=countBits%3;
            //converting binary to decimal
            result=result+(countBits*pow);
            //calculating 2's power each time
            pow=pow<<1;
        }
        return result;
    }
};