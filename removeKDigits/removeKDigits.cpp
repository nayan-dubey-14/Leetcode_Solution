class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        stack<char> s;
        string result="";
        for(int i=0;i<num.size();i++)
        {
            while(!s.empty() && k>0 && s.top()>num[i]) 
            {
                s.pop();
                k--;
            }
            if(!s.empty()) s.push(num[i]);
            else if(s.empty() && (num[i]-48)!=0) s.push(num[i]);
        }
        while(k!=0 && s.size()!=0)
        {
            s.pop();
            k--;
        }
        while(s.size()!=0)
        {
            result+=s.top();
            s.pop();
        }
        if(result.size()==0) return "0";
        reverse(result.begin(),result.end());
        return result;
        
    }
};