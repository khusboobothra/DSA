//Problem : https://www.interviewbit.com/problems/two-teams/

//Approach : use the concept of Bipartite Graph

//Solution:

bool isBipartite(int src,map<int,vector<int>>&adj,vector<int>&color)
{
    if(color[src]==-1)
    {
        color[src]=1;
    }
    for(auto it:adj[src])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[src];
            if(isBipartite(it,adj,color)==false)
            return false;
        }
        else if(color[it]==color[src])
        {
            return false;
        }    
    }
    return true;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    map<int,vector<int>>adj;
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int>color(A+1);
    for(int i=0;i<=A;i++)
    {
        color[i]=-1;
    }

    for(int i=1;i<=A;i++)
    {
        if(color[i]==-1)
        {
            if(isBipartite(i,adj,color)==false)
            return 0;
        }
    }
    return 1;
}
