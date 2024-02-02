int atoi(string s) {
        bool neg=false;
        int i=0;
        int num=0;
        int ans=0;
        if(s[i]=='-') 
        {
            i++;
            neg=true;
        }
        while(i<s.size())
        {
            if(s[i]>=48 && s[i]<=57)
            {
                num=s[i]-48;
                ans=num+ans*10;
                //cout<<ans<<"  "<<num<<endl;
            }
            else return -1;
            i++;
        }
        if(neg==true) return -1*ans;
        return ans;
    }