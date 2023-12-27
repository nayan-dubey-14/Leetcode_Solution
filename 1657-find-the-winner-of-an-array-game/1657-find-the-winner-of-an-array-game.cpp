class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()) return *max_element(arr.begin(),arr.end());
        int count=0;
        int result;
        int e=0;
        int i=1;
        int size=arr.size();
        while(1)
        {
            if(arr[e%size]>arr[i%size])
            {
                count++;
            }
            else
            {
                e=i;
                count=1;
            }
            i++;
            if(count==k) return arr[e];
        }
        return 0;
        
    }
};