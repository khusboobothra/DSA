/*
ARTICULATION POINTS/CUT VERTEX :
An articulation point is a point which when removed makes graph disconnected or more precisely it increases the number of connected components.

Few points to be noted :
1.End points of the bridges will be an articulation point if its degree is greater than 1(>1).
2.It is not neccessary for an articulation point to be an end point of a bridge.
3.Finding bridges algorithm cannot be used to find articulation point

NOTE: Here it is : if(low[it] >= tin[node]) then `node` is an aticulation point.
      whereas, in Finf Bridges case : if(low[it] > tin[node]) then `node-it` edge is a bridge
*/

//CODE :
void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,vector<int>&isArticulation,vector<vector<int>>&adj,int &timer)
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    int child=0;

    for(auto it:adj[node])
    {
        if(it==parent)
        continue;

        if(vis[it]==1)
        {
            //back-edge
            low[node]=min[low[node],tin[it]];
        }
        else
        {
            //forward-edge
            child++;
            dfs(it,node,vis,tin,low,isArticulation,adj,timer);
            low[node]=min(low[node],low[it]);

            if(low[it]>=tin[node] && parent!=-1)
            {
                isArticulation[node]=1;
            }
        }
    }
    if(child>1 && parent==-1)
    isArticulation[node]=1;
}

int main()
{
    //n = number of vertices/nodes and m = number of edges
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(n,0);
    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>isArticulation(n,0);

    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,-1,vis,tin,low,isArticulation,adj,timer);
        }
    }

    for(int i=0;i<n;i++)
    {
        if(isArticulation[i]==1)
        cout<<i<<"is an articulation point."<<"\n";
    }
return 0;
}
