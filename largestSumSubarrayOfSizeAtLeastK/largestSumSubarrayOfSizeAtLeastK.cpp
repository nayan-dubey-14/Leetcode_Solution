long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
      int j=0;
      long long sum=0;
      long long maxSum=-1e9;
      long long backSum=0;
      for(int i=0;i<n;i++)
      {
          sum+=a[i];
          if((i-j+1)==k)
          {
              maxSum=max(maxSum,sum);
          }
          else if((i-j+1)>k)
          {
                  backSum+=a[j++];
                  if(backSum<0) 
                  {
                    sum-=backSum;
                    backSum=0;
                  }
                  maxSum=max(maxSum,sum);
           }
          
      }
      return maxSum;
     }