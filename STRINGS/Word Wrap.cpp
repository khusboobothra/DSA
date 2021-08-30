//Problem : https://practice.geeksforgeeks.org/problems/word-wrap1646/1

//Referenec : https://www.youtube.com/watch?v=FiQY3K4_xPo

//Code :
int calculate(vector<int>&nums,int k,int n)
    {
        int cost[n][n];
        for(int i=0;i<n;i++)
        {
            cost[i][i]=k-nums[i];
            for(int j=i+1;j<n;j++)
            {
                cost[i][j]=cost[i][j-1]-nums[j]-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if (cost[i][j] < 0)
                cost[i][j] = INT_MAX;
            else if (j == n-1 && cost[i][j] >= 0)
                cost[i][j] = 0;
            else
                cost[i][j] = cost[i][j]*cost[i][j];
            }
        }
        int minCost[n];
        for(int i=n-1;i>=0;i--)
        {
            //minCost[i]=denotes minimum cost from ith element to n-1th element(last element)
            minCost[i]=cost[i][n-1];
            for(int j=n-1;j>i;j--)
            {
                if(cost[i][j-1]==INT_MAX)
                continue;
                if(minCost[i]>minCost[j]+cost[i][j-1])
                {
                    minCost[i]=minCost[j]+cost[i][j-1];
                }
            }
        }
        return minCost[0];
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size();
        int ans=calculate(nums,k,n);
        return ans;
    } 
