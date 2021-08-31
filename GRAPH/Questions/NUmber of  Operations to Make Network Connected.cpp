// Problem : https://leetcode.com/problems/number-of-operations-to-make-network-connected/

//Reference : https://www.youtube.com/watch?v=3JIwIRir2sM
/*
Goal: We need to connect all the computers (directly or indirectly). We have to return the minimum number of operations that are required to connect the computers. An operation consists of removing a cable between two directly connected computers and put it between two disconnected computers.

This problem is a simple variation of counting the number of islands.

We know that the minimum number of edges required for a graph with n nodes to remain connected is n - 1. Similarly, if there are k components in a disconnected graph, then we need at least k - 1 edges to connect every component.

With that in our mind, we will start with our base condition. If the number of edges in the graph is greater than n - 1 or not. If not, we will return -1.

Next, we will count the number of components (k). As I already mentioned, we will need k - 1 operations to connect the computers (components). And that is our answer!

*/

// Code :
void dfs(int src,vector<vector<int>>&adj,vector<int>&vis)
    {
          vis[src]=1;
          for(auto it:adj[src])
          {
              if(vis[it]==0)
                  dfs(it,adj,vis);
          }   
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
           adj[connections[i][0]].push_back(connections[i][1]);
           adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
             if(vis[i]==0)
             {
                 count++;
                 dfs(i,adj,vis);
             }
        }
        return count-1;
    }

