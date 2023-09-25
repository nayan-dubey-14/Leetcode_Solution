class Solution {
public:
    char findTheDifference(string str, string t) {
        /*map<char,int> m;
        for(char c:str) m[c]++;
        for(char c:t)
        {
            auto itr=m.find(c);
            if(itr==m.end() || itr->second==0) return c;
            else
            {
                itr->second--;
            }
        }
        return 'o';*/
        int x=0;
        str+=t;
        for(char c:str)
        {
            x=x^c;
        }
        return x;

        
    }
};