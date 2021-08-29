/*Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.
Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:
Each edge in the tree is bi-directional.*/

/*https://www.interviewbit.com/problems/path-with-good-nodes/*/


/*
//Approach: 
You need to find the number of root to leaf paths which contain atmost C good nodes.
So if we start DFS from node 1 and maintain a counter of good nodes seen till now so if we reach a leaf and this count is less than or equal to C then increment the count of paths and go back to previous node.
The point to note here is that in DFS suppose you are at a current node u then the recursion stack contains dfs calls from root to this u so that’s why we can maintain a count of good nodes and while going back we can decrement it simultaneously.

Time Complexity: O(N)
*/

//Solution : 

void dfs(vector<int> &A, vector<bool> &visited, int C,int u,vector<vector<int> > &adj, int &count,int good)
{
  //general Node
    if(good+A[u-1]>C)
    return ;
    
    //leaf Node
    if(adj[u].size()==1 && !visited[u] && C>=good+A[u-1])
    {
    count++;
    return;
    }
      //else go forward
    visited[u]=true;
    
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visited[adj[u][i]])
        {
          dfs(A,visited,C,adj[u][i],adj,count,good+A[u-1]);     
        }
        
    }
    
 return ;   
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int count = 0;
    vector<bool> visited(A.size()+1,false);
    vector<vector<int> > adj(A.size()+1);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    
  dfs(A,visited,C,1,adj,count,0);
  return count;
}

