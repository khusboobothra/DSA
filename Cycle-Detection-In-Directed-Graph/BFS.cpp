//using the logicof Kahn's Algorithm
//Kahn's algorithm is only valid for DAG(Directed-Acyclic-Graph).So,if we're able to do the topo-sort of all the elements using Kahn's algorithm,then the graph is DAG and no cycle is found in the graph else cycle is there in the graph if the number of elements in topo-sort vector not equal to number of elements/nodes.

bool isCycle(int v,vector<vector<int>>&adj)
{
    queue<int>q;
    vector<int>inDegree(v,0);
    vector<int>topo;
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            inDegree[it]++;
        }
    }

    for(int i=0;i<v;i++)
   {
       if(inDegree[i]==0)
       q.push(i);
   }

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
   if(topo.size()==v)
   return false;
   else
   return true;
}