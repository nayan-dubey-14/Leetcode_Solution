class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr(rowIndex+1);
        int m=0;
        int n=1;
        for(int i=0;i<=rowIndex;i++)
        {
            if(i==0 || i==1) for(int e=0;e<=i;e++) arr[i].push_back(1);
            else
            {
                arr[i].push_back(1);
                for(int e=1;e<i;e++)
                {
                    arr[i].push_back(arr[i-1][m]+arr[i-1][n]);
                    m++;
                    n++;
                }
                arr[i].push_back(1);
                m=0;
                n=1;
            }
        }
        return arr[rowIndex];
    }
};