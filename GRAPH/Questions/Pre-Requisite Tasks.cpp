// Problem : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/0/?company[]=Twitter&page=1&query=company[]Twitterpage1#

// Code :

bool isDfs(int src,vector<int>adj[],vector<int>&vis)
{
    if(vis[src]==1)
    return true;

    if(vis[src]==0)
    {
        vis[src]=1;
        for(auto it:adj[src])
        {
            if(isDfs(it,adj,vis))
            return true;
        }
    }
    vis[src]=2;
    return false;
}

bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	vector<int>adj[N];
    for(auto it:prerequisites)
    {
        adj[it.second].push_back(it.first);
    }
    
    vector<int>vis(N,0);

    for(int i=0;i<N;i++)
    {
        if(isDfs(i,adj,vis))
        return false;
    }
    return true;
}