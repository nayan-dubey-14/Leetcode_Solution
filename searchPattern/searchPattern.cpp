int txtSize=txt.size();
            int patSize=pat.size();
            vector<int> result;
            for(int i=0;i<=txtSize-patSize;i++)
            {
                if(txt[i]==pat[0] && txt.substr(i,patSize)==pat) result.push_back(i+1);
            }
            if(result.size()==0) result.push_back(-1);
            return result;