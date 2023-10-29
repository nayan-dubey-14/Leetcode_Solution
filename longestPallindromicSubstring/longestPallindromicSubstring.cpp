class Solution {
public:
    string longestPalindrome(string str) {
        int s,e;
        string result="";
        result+=str[0];
        int largest=0;
        int low=0,high=0;
        int size=str.size();
        for(int i=0;i<size;i++)
        {
            s=i-1;
            e=i+1;
            //each time checking for odd pallindromic substring
            while((s>=0 && e<size) && (str[s]==str[e]))
            {
                if((e-s+1)>largest)
                {
                    largest=(e-s+1);
                    low=s;
                    high=e;
                }
                s--;
                e++;
            }
            s=i;
            e=i+1;
            //each time checking for even pallindromic substring
            while((s>=0 && e<size) && (str[s]==str[e]))
            {
                if((e-s+1)>largest)
                {
                    largest=(e-s+1);
                    low=s;
                    high=e;
                }
                s--;
                e++;
            }
        }
        //if low and high are not same means we find the index of longest substring
        if(low!=high)
        {
            result="";
            while(low<=high) result+=str[low++];
        }
        return result;
        
    }
};