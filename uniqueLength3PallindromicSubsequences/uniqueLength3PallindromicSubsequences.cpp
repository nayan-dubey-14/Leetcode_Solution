class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result=0;
        vector<int> first(26,-1);
        vector<int> second(26,-1);
        for(int i=0;i<s.size();i++)
        {
            if(first[s[i]-97]==-1)
            {
                first[s[i]-97]=i;
            }
            else second[s[i]-97]=i;
        }
        for(int i=0;i<26;i++)
        {
            unordered_set<char> set;
            if(first[i]!=-1 && first[i]!=second[i])
            {
                for(int e=first[i]+1;e<second[i];e++)
                {
                    set.insert(s[e]);
                }
                result+=set.size();
            }
        }
        return result;
        
    }
};