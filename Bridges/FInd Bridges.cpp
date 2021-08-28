/*
BRIDGE : A bridge is defined as an edge which when removed makes graphs disconnected or more precisely it oimcreases the number of components int the graph. 
tin[] :  it denotes the time at which a node enters(a dfs call)
low[] : it denotes the time of lowest ancestor(not the parent) which can be reached directly from that node(back-edge)
*/





void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,int &timer,vector<int>&adj)
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;

    for(auto it:adj[node])
    {
        if(it==parent)
        continue;

        if(vis[it]==1)
        //it is visited and it is not the parent, hence a back edge is found between node and it
        {
            low[it]=min(low[node],tin[it]);
        }
        else
        {
        //forward edge
        dfs(it,node,vis,tin,low,timer,adj);
        low[node]=min(low[it],low[node]);
        if(low[it]>tin[node])
        {   
            //edge is found
            cout<<node<<"-"<<it<<"is a bridge"<<"\n";
        }
        
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(vis[i]==0) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}

