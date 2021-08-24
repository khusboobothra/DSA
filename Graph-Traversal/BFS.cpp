vector<int>bfs(int v,vector<vector<int>>adj)
{
    vector<int>bfsArray;
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(vis[i]==0)
        {
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                int node=q.top();
                q.pop();
                bfsArray.push_back(node);

                for(auto it:adj[node])
                {
                    if(vis[it]==0)
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfsArray;
}