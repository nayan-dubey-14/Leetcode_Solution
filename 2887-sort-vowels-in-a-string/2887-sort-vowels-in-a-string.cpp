class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
    }
    string sortVowels(string s) {
        vector<int> arr;
        string tmp;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i])==true) 
            {
            arr.push_back(i);
            tmp+=s[i];
            }
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<arr.size();i++)
        {
            s[arr[i]]=tmp[i];
        }
        return s;
        
    }
};