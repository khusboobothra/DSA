bool dfs(int node,vector<vector<int>>&adj,vector<int>&color)
{
    if(color[node]==-1)
    color[node]=1;

    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[node];
            if(!dfs(it,node,adj,vis))
            return false;
        }
        else if(color[it]==color[node])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int v,vector<vector<int>>&adj)
{
    vector<int>color(v+1);
    memset(color,-1,sizeof(color));
    for(int i=1;i<=v;i++)
    {
        if(color[i]==-1)
        {
            if(!dfs(i,adj,color))
            return false;
        }
    }
    return true;
}