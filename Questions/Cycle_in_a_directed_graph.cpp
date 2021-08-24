//Approach:Refer cycle in a dirceted graph(DFS) in the notes section.

bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsVis)
{
    vis[node]=1;
    dfsVis[node]=1;

    for(auto it:adj[node])
    {
        if(vis[it]==0)
      {
         if( dfs(it,adj,vis,dfsVis))
          {
              return true;
          }
      }
      else if(dfsVis[it])
      {
          return true;
      }
    }
    dfsVis[node]=0;
    return false;
}




int Solution::solve(int A, vector<vector<int> > &B) {
    if(A==1)
    return 0;
    vector<vector<int>>adj(A+1);

    for(int i=0;i<B.size();i++)
    {
            adj[B[i][0]].push_back(B[i][1]);
    }
    vector<int>vis(A+1,0);
    vector<int>dfsVis(A+1,0);
    for(int i=1;i<=A;i++)
   {
     if(vis[i]==0)
     {
         if(dfs(i,adj,vis,dfsVis))
         return 1;
     }
   }
   return 0;
}

