void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st)
{
vis[node]=1;

for(auto it:adj[node])
{
if(vis[it]==0)
{
    dfs(it,adj,vis,st);
}
}
st.push(node);
}

vector<int>topo(int vector<vector<int>>&adj)
{
    vector<int>vis(v+1,0);
    stack<int>st;

    for(int i=1;i<=v;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,adj,vis,st);
        }
    }

    vector<int>topoSort;

    while(!st.empty())
    {
        topoSort.push_back(st.top());
        st.pop();
    }
    return topoSort;
}