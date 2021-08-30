#include<bits/stdc++.h>
using namepsace std;

int main()
{
    int n,m;
    cin>>n>>m;
    //n=number of vertices in the graph
    //m=number of edges in the graph
    vector<vector<int>>adj;
    for(int i=0;i<m;i++)
    {
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);

     //for directed graph
     //adj[u].push_back(v);
    }
}