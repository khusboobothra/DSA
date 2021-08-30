//Time Complexity:O(VlogV)
/*Optimization:In brute-force approach we run a loop for calculating minimum vertex among the unvisited vertex which takes O(n) time.Instead, we can use priority queue which helps us find minimum vertex in log(N) time which is less than O(n) time.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //n=number of vertices and m=number of edges
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;

        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    int parent[n+1];
    int key[n+1];
    int mst[n+1];

    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
        key[i]=INT_MAX;
        mst[i]=false;
    }

    //pair<int,int> = pair<key_value,vertex>
    
    //Here ,the priority queue is arranged on the basis of key_value
    //priority-queue is min-heap i.e lower value remains at the front
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    key[0]=0;
    parent[0]=-1;
    pq.push_back({0,0});

    for(int edges=0;edges<n-1;edges++)
    {
        int u=pq.pop().second;
        pq.pop();
        mst[u]=true;

        for(auto it : adj[u])
        {
            int v=it.first();
            int weight=it.second();

            if(mst[v]==false && weight<key[v])
            {
                key[v]=weight;
                parent[v]=u;
                pq.push(make_pair(key[v],v));
            }
        }
        
    }

    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<"-"<<i<<"\n";
    }
    return 0;

}
