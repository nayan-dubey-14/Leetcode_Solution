class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1,m2;
        int count=0;
        //first we maintain the count of char of s
        for(int i=0;i<s.size();i++) m1[s[i]]++;
        //then we decrease the count of same chars present in s and t
        for(int i=0;i<t.size();i++) m1[t[i]]--;
        //now we add the remaining difference of both chars
        for(auto itr:m1) count+=abs(itr.second);
        return count;
    }
};
