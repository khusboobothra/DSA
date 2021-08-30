bool checkdfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dfsVis)
{
    vis[node]=1;
    dfsVis[node]=1;

    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            if(checkdfs(it,adj,vis,dfsVis))
            return true;
        }
        else if(dfsVis[it])
        return true;
    }
    dfsVis[node]=0;
    return false;
}

bool isCycle(int v,vector<vector<int>>&adj)
{
    vector<int>vis(v,0);
    vector<int>dfsVis(v,0);
    for(int i=1;i<=v;i++)
    {
        if(vis[i]==0)
        {
            if(checkdfs(i,adj,vis,dfsVis))
            return true;
        }
    }
    return false;
}