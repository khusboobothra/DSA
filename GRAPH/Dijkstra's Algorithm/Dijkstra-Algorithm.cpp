//Problem: Given a graph and a source vertex in the graph,find the shortest paths from source to all vertices in the graph.
//valid  for weighted + undirected + connected graph only
//SOURCE TO ALL NODES

//Code

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //n=number of vertices and m=number of edges
    int n,m;
    int src;
    cin>>n>>m;
    cin>>src;

    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++)
    {
        int a,b,wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    vector<int>disTo(n+1);
    disTo[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push_back(make_pair(0,src));

    while(!pq.empty())
    {
        int prevNode=pq.top().second;
        int prevDis=pq.top().first;
        pq.pop();
 
       //relaxing all the adjacent nodes
        for(auto it:adj[prevNode])
        {
            int nextNode=it.first;
            int nextDis=it.second;

            if(disTo[nextNode]>nextDis+prevDis)
            {
                disTo[nextNode]=nextDis+prevDis;
                pq.push(make_pair(disTo[nextNode],nextNode));
            }
        }
    }
    cout<<"The distance from source"<<src<<"is"<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<disTo[i]<<" ";
    }
    return 0;
}

//Time-Complexity: