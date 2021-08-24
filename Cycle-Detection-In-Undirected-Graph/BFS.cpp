bool checkForCycle(int src,vector<vector<int>>&adj,vector<int>&vis)
{
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src]=1;

    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;

        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if(it!=parent)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int v,vector<vector<int>>&adj)
{
    vector<int>vis(n+1,0);
    for(int i=1;i<=v;i++)
    {
        if(vis[i]==0)
        {
            if(checkForCycle(i,adj,vis))
            {
                return true;
            }
        }
    }
    return false;
}