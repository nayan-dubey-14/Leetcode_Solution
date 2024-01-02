class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        int max=0;
        for(int i:nums) m[i]++;
        for(auto itr:m) if(itr.second>max) max=itr.second;
        vector<vector<int>> arr(max);
        for(auto itr:m)
        {
            for(int i=0;i<itr.second;i++)
            {
                arr[i].push_back(itr.first);
            }
        }
        return arr;
    }
};