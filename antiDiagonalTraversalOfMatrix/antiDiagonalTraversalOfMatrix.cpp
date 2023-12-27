void printDiagonal(int r,int c,vector<vector<int>> &arr,vector<int> &result)
    {
        int size=arr.size();
        while(r<size && c>=0)
        {
            result.push_back(arr[r++][c--]);
        }
    }
vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> result;
        int i=0;
        int j=0;
        int n=matrix.size();
        while(i<n)
        {
            printDiagonal(i,j,matrix,result);
            if(j<n) j++;
            if(j==n)
            {
                j=n-1;
                i++;
            }
        }
        return result;
        
    }