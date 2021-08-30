// Problem : https://leetcode.com/problems/cheapest-flights-within-k-stops/

//Solution :
//USing Dijkstra's Algorithm(Prefered)
 //using dijkstra's algorithm
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto it : flights)
        {
            graph[it[0]].push_back({it[1],it[2]});
        }
        //dis[i] denotes the minimum distance of i from src
        vector<int>dis(n,-1);
        queue<pair<int,int>>q;
        q.push({src,0});
        //k stops means k nodes in between means k+1 edges
        k++;
        while(!q.empty())
        {
            if(k==0)
                break;
            int len=q.size();
            
            while(len--)
            {
            auto curr=q.front();
            q.pop();
                for(auto it:graph[curr.first])
            {
                //price= price to reach from [0,curr]+price to reach from [curr,it]
                int price=curr.second+it.second;
                //if it is visited first time then,this price will be eqaul to dis[it] else if it is already visited then if price is less then dis[price] then only we'll update price
                if(dis[it.first]==-1 || price<dis[it.first])
                {
                    dis[it.first]=price;
                    q.push({it.first,dis[it.first]});
                }
            }
            }
            
                 k--;
        }
   
         return dis[dst];
    } 




//Using DP[Dynammic Programming]
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        //dp[i][j] = Dist to reach j using atmost i edges from src
        
        for(int i = 0; i <= K+1; i++)
        {
            dp[i][src] = 0; // Dist to reach src always zero
        }
        
        for(int i = 1; i <= K+1; i++)
        {
            for(auto &f: flights)
            {
                //Using indegree
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }
        
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
    }