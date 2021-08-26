/*
Problem : Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

https://www.interviewbit.com/problems/cycle-in-undirected-graph/

*/

//Solution
bool dfs(int src,int parent,vector<vector<int>>&adj,vector<bool>&vis)
{
    vis[src]=true;
    for(auto it:adj[src])
    {
        if(vis[it]==false)
        {
            if(dfs(it,src,adj,vis))
            return true;
        }
        else if(it!=parent)
        {
            return true;
        }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
if(A==0 || A==1 || A==2)
return 0;

vector<vector<int>>adj(A+1);
for(int i=0;i<B.size();i++)
{
    adj[B[i][0]].push_back(B[i][1]);
    adj[B[i][1]].push_back(B[i][0]);
}
vector<bool>vis(A+1,false);

for(int i=1;i<=A;i++)
{
    if(vis[i]==false)
    {
        if(dfs(i,-1,adj,vis))
        return 1;
    }
}
return 0;
}