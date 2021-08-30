#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    //n=number of vertices in thr graph
    //m=number of edges in the graph
    int adj[n][n];
    for(int i=0;i<m;i++)
    {
       int u,v;
       cin>>u>>v;
       adj[u][v]=1;
       adj[v][u]=1;
       
       //for-directed-graph
       //adj[u][v]=1;
    }
}