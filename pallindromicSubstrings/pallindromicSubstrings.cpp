class Solution {
public:
    int countSubstrings(string str) {
        int count=0;
        int s,e;
        int size=str.size();
        for(int i=0;i<size;i++)
        {
            count++;
            s=i-1;
            e=i+1;
            while((s>=0 && e<size) && (str[s]==str[e]))
            {
                count++;
                s--;
                e++;
            }
            s=i;
            e=i+1;
            while((s>=0 && e<size) && (str[s]==str[e]))
            {
                count++;
                s--;
                e++;
            }
        }
        return count;
    }
};