bool bfsBipartite(int src,vector<vector<int>>&adj,vector<int>&color)
{
    color[src]=1;
    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
           {
               return false;
           }
        }
    }
    return true;
}

bool checkBipartite(int v,vector<vector<int>>&adj)
{
    vector<int>color(v);
    memset(color,-1,sizeof(color));
    for(int i=1;i<=v;i++)
    {
        if(color[i]==-1)
        {
            if(!bfs(i,adj,color))
            return false;
        }
    }
    return true;
}