/*
//Problem : 
Rishabh has a permutation A of N integers 1, 2, ... N but he doesn't like it. Rishabh wants to get a permutation B.
Also, Rishabh has some M good pairs given in a form of 2D matrix C of size M x 2  where (C[i][0], C[i][1]) denotes that two indexes of the permutation A.In one operation he can swap Ax and Ay only if (x, y) is a good pair.

You have to tell whether Rishabh can obtain permutation B by performing the above operation any number of times on permutation A.
If the permutation B can be obtained return 1 else return 0.

https://www.interviewbit.com/problems/permutation-swaps/

*/

//Solution :

#include<bits/stdc++.h>

bool isReachable(int src, int des, unordered_map<int, vector<int>> &g, vector<bool> &visited){
    if(src==des) return true;
    visited[src]=true;
    for(auto neighbour: g[src]){
        if(!visited[neighbour]){
            if(isReachable(neighbour, des, g, visited)) 
            return true;
        }
    }
    return false;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C){
    unordered_map<int, vector<int>> g;
    for(int i=0; i<C.size(); i++){
        g[A[C[i][0]-1]].push_back(A[C[i][1]-1]);
        g[A[C[i][1]-1]].push_back(A[C[i][0]-1]);
    }
    for(int i=0; i<A.size(); i++){
        //defining visited array for every node
        vector<bool>visited(A.size()+1,false);
        if(A[i]!=B[i]){
            if(!isReachable(A[i], B[i], g, visited)) return 0;
        }
    }
    return 1;
}