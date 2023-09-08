class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i=0;
        int m=0;
        int n=1;
        vector<vector<int>> result;
        vector<int> v;
        while(i<numRows)
        {
            if(i==0 || i==1) for(int e=0;e<=i;e++) v.push_back(1);
            else
            {
                v.push_back(1);
                for(int e=1;e<=i;e++) 
                {
                    if(e==i) v.push_back(1);
                    else
                    {
                        v.push_back(result[i-1][m]+result[i-1][n]);
                        m++;
                        n++;
                    }
                }
            }
            result.push_back(v);
            v.clear();
            i++;
            m=0;
            n=1;
        }
        return result;
        
    }
};