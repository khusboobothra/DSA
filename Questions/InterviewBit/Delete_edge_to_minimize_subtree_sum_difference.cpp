//Problem: https://www.geeksforgeeks.org/delete-edge-minimize-subtree-sum-difference/

/*
//Approach:
1. Brute-force algorithm : Delete each edge and check the subtree difference one-by-one.(TC:quadratic amount of time)
2. Optimised algorithm : Calculating the total tree sum(S) first, then doing dfs call.During each dfs call we calculate its subtree sum(S1) then the other subtree sum will be equal to (S2=S-S1).(Takes linear time)

In below code, another array subtree is used to store sum of subtree rooted at node i in subtree[i]. DFS is called with current node index and parent index each time to loop over children only at each node. 
*/

//Solution:

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int totalSum, vector<vector<int>>&adj,vector<int>&subtree,int &res)
{
    int sum=subtree[node];
    /*loop for all neighbors except parent and
        aggregate sum over all subtrees */

    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            dfs(it,node,adj,subtree,res);
            sum=sum+subtree[it];
        }
    }
    subtree[node]=sum;
    
     /* at one side subtree sum is 'sum' and other side
        subtree sum is 'totalSum - sum' so their difference
        will be totalSum - 2*sum, by which we'll update
        res */
    if(node!=0 && res>abs(totalSum-(2*sum)))
    {
        res=abs(totalSum-(2*sum));
    }
}

int getMinSubtreeSumDifference(int vertex[],edges[][2],int N)
{
    int totalSum=0;
    vector<int>subtree[N];

    for(int i=0;i<N;i++)
    {
        totalSum+=vertex[i];
        subtree[i]=vertex[i];
    }

    vector<vector<int>>adj(N);

    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

     int res=INT_MAX;
     //calling dfs with node '0' and parent ans -1
     dfs(0.-1,adj,totalSum,subtree,res);

     return res;
}

int main()
{
    int vertex[] = {4, 2, 1, 6, 3, 5, 2};
    int edges[][2] = {{0, 1}, {0, 2}, {0, 3},
                    {2, 4}, {2, 5}, {3, 6}};
    int N = sizeof(vertex) / sizeof(vertex[0]);
 
    cout << getMinSubtreeSumDifference(vertex, edges, N);
    return 0;
}
