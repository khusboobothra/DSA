//Problem:Find the minimum spanning truee using Kruskal's ALgorithm

/*

Approach:
1.Sort all edges in graph 'G' in order of their increasing weights.
2.Repeat (v-1) times-[as MST must contain V-1 edges]
{
    2.1. Select the next edge with minimum weight from graph 'G.
    2.1.2. If (no cycle is formed by adding the edge i.e the edge connects two different connected components)
    {
        Add it to the MST.
    }    
}
3.Print the cost and the MST.

*/

//Code:
#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,
    int v,
    int wt,
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};

void comp(node a, node b)
{
    return a.wt<b.wt;
}

int findPar(int node,vector<int>&parent)
{
    if(node==parent[node])
    return node;

    return parent[node]=findPar(parent[node]);
}

void union(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findPar(u,parent);
    v=findPar(v,parent);

    if(rank[u]<rank[v])
    parent[u]=v;

    else if(rank[u]>rank[v])
    parent[v]=u;

    else
    {
        rank[u]++;
        parent[v]=u;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<node>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }

    //sort takes a third parameter that is used to specify the order of the edges is to arranged.
    sort(edges.begin(),edges.end(),comp);

    vector<int>parent(n);
    vector<int>rank(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    //this stores all the edges of the MST.
    vector<pair<int,int>>mst;
    int cost=0;

    for(auto it:edges)
    {
        int u=it.first;
        int v=it.second;

        if(findPar(u,parent)!=findPar(v,parent))
        {
            cost=cost+it.weight;
            mst.push_back(make_pair(u,v));
            union(u,v,parent,rank);
        }
    }
    cout<<"Cost of MST is:"<<cost<<"\n";
    //printing the edges of mst
    for(auto it:mst)
    {
        cout<<it.first<<"->"<<it.second<<"\n";
    }
    return 0;
}























//Time Complexity:
