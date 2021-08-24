/* Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.*/

/*https://www.interviewbit.com/problems/word-search-board/ */

//Solution
bool dfs(int i,int j,vector<string>&A,int index,string B)
{
    if(i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j]!=B[index])
    return false;

    if(index==B.length()-1)
    return true;

    if(dfs(i+1,j,A,index+1,B))
    return true;

    if(dfs(i-1,j,A,index+1,B))
    return true;

    if(dfs(i,j-1,A,index+1,B))
    return true;

    if(dfs(i,j+1,A,index+1,B))
    return true;  

    return false;
}

int Solution::exist(vector<string> &A, string B) {
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
             if(B[0]==A[i][j])
             {
             if(dfs(i,j,A,0,B))
             return 1;
             }
        }
    }
    return 0;
}

