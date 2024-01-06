void calSPF(vector<int> &arr)
    {
        for(int i=1;i<arr.size();i++) arr[i]=i;
        for(int i=4;i<arr.size();i+=2) arr[i]=2;
        for(int i=3;i<arr.size();i+=2)
        {
            if(arr[i]==i)
            {
                for(int e=i*i;e<arr.size();e+=i)
                {
                    arr[e]=i;
                }
            }
        }
    }
	int sumOfPowers(int a, int b){
	    vector<int> arr(b+1);
	    calSPF(arr);
	    int count=0;
	    int num;
	    for(int i=a;i<=b;i++)
	    {
	        num=i;
	        while(num!=1)
	        {
	            count++;
	            num=num/arr[num];
	        }
	    }
	    return count;
	    
	}