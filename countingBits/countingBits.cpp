class Solution {
public:
    vector<int> countBits(int n) {
        int m,count;
        vector<int> result;
        for(int i=0;i<=n;i++)
        {
            m=i;
            count=0;
            while(m!=0)
            {
            if(m&1) count++;
            m=m>>1;
            }
            result.push_back(count);
        }
        return result;
    }
};