public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>> s;
        vector<int> result;
        for(int i=0;i<matrix.size();i++)
        {
            auto itr=s.find(matrix[i]);
            if(itr==s.end()) s.insert(matrix[i]);
            else result.push_back(i);
        }
        return result;
    } 