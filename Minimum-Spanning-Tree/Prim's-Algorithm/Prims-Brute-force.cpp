//Problem:Find the minimum spanning truee using Prim's ALgorithm

/*
1.MST[]:It is a boolean array that tells whether a vertex is included in MST or not. If MST[i]=T,then vertex i is included in MST , else not.
2.KEY[]:This array is used to store the weight corresponding to the vertex
3.PARENT[]:This array stores the parent node of the vertex in MST

STEPS:
1.Select a vetex(say A).
2.Figure out the edge from the vextex(A) which has minimum edge weight and is not a marked as true in MST.(A->B)
3.Mark B vertex as true in MST array(MST[B]=T) and do PARENT[B]=A and KEY[B]=edge weight of A->B
*/

//CODE

#include<bits/stdc++.h>
using namespace std;


int selectMinVertex(int key[],int mst[])
{
    int minimum = INT_MAX;
    int vertex;


    for(int i=0;i<n;i++)
    {
       if(mst[i]==false && key[i]<minimum)
       {
           vertex=i;
           minimum=key[i];
       } 
    }
    return vertex;
}

int main()
{
    //n=number of vertices and m=number of edges
    int n,m;
    cin>>n>>m;
    vector<vector<int,int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
      int a,b,wt;
      cin>>a>>b>>wt;
      adj[a].push_back(make_pair(b,wt));
      adj[b].push_back(make_pair(a,wt));
    }
    int parent[n+1];
    int mst[n+1];
    int key[n+1];

    for(int i=0;i<=n;i++)
    {
        parent[i]=-1;
        mst[i]=false;
        key[i]=INT_MAX;
    }

    key[0]=0;
    parent[0]=-1;

    //Form MST with (n-1) edges
    for(int edges=0;edges<n-1;edges++)
    {
        //select the best vertex by applying greedy method
        //our edge will be u -> v
        int u=selectMinVertex(key,mst);

        mst[u]=true;

        //relax the adjacent vertices which are not yet included in the mst
        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;

            if(mst[v]==false && key[v]>weight)
            {
                key[v]=weight;
                parent[v]=u;
            }
        }
    }

for(int i=1;i<n;i++)
{
cout<<parent[i]<<"-"<<i<<"\n";
}
return 0;
}

//Time Complexity:O(v*V)