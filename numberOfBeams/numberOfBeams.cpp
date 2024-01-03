class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int size=bank.size();
        int s=bank[0].size();
        int result=0;
        int prevCount=0;
        int count=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(bank[i][j]==49) count++;
            }
            if(count==0) continue;
            if(i>0)
            {
                result+=prevCount*count;
            }
            prevCount=count;
            count=0;
        }
        return result;
        
    }
};