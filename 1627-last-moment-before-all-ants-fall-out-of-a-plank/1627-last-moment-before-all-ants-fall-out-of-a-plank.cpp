class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size()==0 && right.size()==0) return 0;
        int maxItr;
        int minItr;
        if(right.size()!=0) minItr=*min_element(right.begin(),right.end());
        if(left.size()!=0) maxItr=*max_element(left.begin(),left.end());
        if(left.size()==0) return n-(minItr);
        else if(right.size()==0) return maxItr;
        else
        {
            int tmp=n-(minItr);
            if(tmp<(maxItr)) return maxItr;
            return tmp;
        }
        return 0;
    }
};