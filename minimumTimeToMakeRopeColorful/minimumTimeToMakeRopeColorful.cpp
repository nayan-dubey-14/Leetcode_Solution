class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int j=1;
        int time=0;
        while(j<=colors.size())
        {
            if(colors[i]==colors[j])
            {
                if(neededTime[i]<=neededTime[j]) time+=neededTime[i];
                else
                {
                    time+=neededTime[j];
                    swap(neededTime[i],neededTime[j]);
                }
            }
            i++;
            j++;
        }
        return time;
    }
};