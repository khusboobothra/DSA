//Kahn's algorithm:Here we use the concept of indegree
//Take out the indegree of all the nodes present in the graph.The nodes with indegree=0,are pushed to the queue first.Then ,simply apply bfs and keep decreasing the indegree when the node is visited.Add the nodes to the topo-sort when you pop them out of the queue.

vector<int>topoSort(int v,vector<vector<int>>&adj)
{
    queue<int>q;
    vector<int>inDegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            inDegree[it]++;
        }
    }

    for(in ti=0;i<n;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty())
    {
        int node=q.top();
        q.pop();
        topo.push_back(node);

        for(auto it:adj[node])
        {
            inDegree[it]--;

            if(inDegree[it]==0)
            q.push(it);
        }
    }
}