bool checkForCycle(int node,int parent,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[node]=1;

    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            if(checkForCycle(it,node,adj,vis))
            return true;
        }
        if(it!=parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int v,vector<vector<int>>&adj)
{
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(vis[i]==0)
        {
            if(checkForCycle(i,-1,adj,vis))
            return true;
        }
   }
   return false;
}