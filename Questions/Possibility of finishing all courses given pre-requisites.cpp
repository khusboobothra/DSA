/*
Problem : 
There are a total of A courses you have to take, labeled from 1 to A.
Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.

https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

*/

//Approach :The problem reduces down to finding a directed cycle in the whole graph. If any such cycle is present, it is not possible to finish all the courses.This problem reduces to find cycle in a directed graph

//Solution

bool isCyclic(int v, vector<bool> &vis, vector<bool> &dfs, vector<int> adj[]) {
    
        vis[v] = true;
        dfs[v] = true;
        
        for(auto a: adj[v]) {
            if(vis[a]==false)
            {
                if(isCyclic(a,vis,dfs,adj))
                return true;
            }
            else if(dfs[a])
            {
                return true;
            }
        }
    dfs[v] = false;
    return false;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int V = A;
    int E = B.size();
    
    vector<int> adj [V];
    vector<bool> vis(A, false);
    vector<bool> dfs(A, false);
    
    for(int i=0;i<E;i++)
        adj[B[i]-1].push_back(C[i]-1);
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
           {
               if(isCyclic(i, vis, dfs, adj))
            return 0;
        }
    }
       
    return 1;
}