class Solution {
public:
    bool halvesAreAlike(string s) {
        int e,f,count1,count2;
        count1=count2=0;
        e=s.size()/2;
        f=e-1;
        while(f>=0)
        {
            if(s[e]=='a' || s[e]=='e' || s[e]=='i' || s[e]=='o' || s[e]=='u' || s[e]=='A'|| s[e]=='E' || s[e]=='I' || s[e]=='O' || s[e]=='U') count1++;
            if(s[f]=='a' || s[f]=='e' || s[f]=='i' || s[f]=='o' || s[f]=='u' || s[f]=='A'|| s[f]=='E' || s[f]=='I' || s[f]=='O' || s[f]=='U') count2++;
             f--;
             e++;
        }
        return count1==count2;
    }
};