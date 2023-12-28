bool match(string wild, string pattern)
    {
        int wLen=wild.size();
        int pLen=pattern.size();
        int i=0;
        int j=0;
        int lastStar=-1;
        int lastCharMatch=-1;
        while(j<pLen)
        {
            if(i<wLen && (wild[i]=='?' || wild[i]==pattern[j]))
            {
                i++;
                j++;
            }
            else if(i<wLen && wild[i]=='*')
            {
                lastStar=i;
                lastCharMatch=j;
                i++;
            }
            else if(lastStar==-1) 
            {
                return false;
            }
            else
            {
                i=lastStar+1;
                j=++lastCharMatch;
            }
        }
        while(i<wLen)
        {
            if(wild[i++]!='*') return false;
        }
        return true;
    }