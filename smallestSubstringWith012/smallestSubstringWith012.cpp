int smallestSubstring(string s) {
        int e,f,g;
        e=f=g=-1;
        int mx,mn,diff,smallest=INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==48) e=i;
            else if(s[i]==49) f=i;
            else g=i;
            if(e!=-1 && f!=-1 && g!=-1)
            {
                mx=max({e,f,g});
                mn=min({e,f,g});
                diff=mx-mn+1;
                if(smallest>diff) smallest=diff;
            }
        }
        if(smallest==INT_MAX) return -1;
        return smallest;
    }