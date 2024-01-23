class Solution {
public:
    int maxLen=0;
    void findLength(vector<string> &arr,vector<int> &tmp,int start,int end,int &length)
    {
        if(start==end)
        {
            if(length>maxLen) maxLen=length;
            return;
        }
        string s=arr[start];
        bool found=false;
        int index=0;
        for(char c:s)
        {
            if(tmp[(int)c-97]==1) 
            {
                found=true;
                break;
            }
            tmp[(int)c-97]=1;
            index++;
        }
        if(found==false)
        {
        length+=s.size();
        findLength(arr,tmp,start+1,end,length);
        for(char c:s) tmp[(int)c-97]=0;
        length-=s.size();
        }
        if(found==true) for(int i=0;i<index;i++) tmp[(int)s[i]-97]=0;
        findLength(arr,tmp,start+1,end,length);
    }
    int maxLength(vector<string>& arr) {
        vector<int> tmp(26,0);
        int start=0;
        int end=arr.size();
        int length=0;
        findLength(arr,tmp,start,end,length);
        return maxLen;
    }
};