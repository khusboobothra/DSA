/* Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size 
M x 2 such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.
Return 1 if path exists else return 0.*/

/* https://www.interviewbit.com/problems/path-in-directed-graph/# */


//Solution
void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        if(vis[it]==false)
        dfs(it,adj,vis);
    }
}

int solve(int A,vector<vector<int>>&B)
{
    vector<vector<int>>adj(A+1);
    vector<bool>vis(A+1,false);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    dfs(1,adj,vis);
    if(vis[A])
    return 1;
    else
    return 0;
}