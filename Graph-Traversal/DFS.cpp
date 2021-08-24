void dfsSolve(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>dfsArray)
{
vis[node]=1;
dfsArray.push_back(node);

for(auto it:adj[node])
{
    if(vis[it]==0)
    {
        dfsSolve(it,adj,vis,dfsArray);
    }
}
}

vector<int>dfs(int v,vector<vector<int>>&adj)
{
    vector<int>vis(v+1,0);
    vector<int>dfsArray;

    for(int i=1;i<=v;i++)
    {
        if(vis[i]==0)
        {
            dfsSolve(i,adj,vis,dfsArray);
        }
    }
    return dfsArray;
}