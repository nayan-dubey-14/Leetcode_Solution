class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m;
        //take a map and iterate over given 2-D array
        //each element of pair will act as a key,value in map
        for(auto arr:adjacentPairs)
        {
            m[arr[0]].push_back(arr[1]);
            m[arr[1]].push_back(arr[0]);
        }
        //now create the final array with size+1 as given in question
        vector<int> result(adjacentPairs.size()+1);
        int i=0;
        //iterate over map till we find that key's value whose array size==1
        //basically 2 key's have array of size==1 ,which are the starting element of final array
        for(auto itr:m)
        {
            if(itr.second.size()==1)
            {
                //insert first two elements in final array
                result[i++]=itr.first;
                result[i++]=itr.second[0];
                break;
            }
        }
        int prevAdj=result[0]; //prev's element before adjacent
        int prev=result[1];   // the prev element
        int current;  // prev's element after adjacent
        while(i<result.size())
        {
            current=m[prev][0];
            if(current==prevAdj) current=m[prev][1]; //if current is equal to before adjacent,it means it already exists so we update it
            result[i++]=current;
            prevAdj=prev;
            prev=current;
        }
        return result;
        
    }
};