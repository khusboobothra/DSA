/* Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.*/

/* https://www.interviewbit.com/problems/capture-regions-on-board/*/

//Approach:

//Solution
void dfs(int i,int j,vector<vector<char>>&A)
{
if(A[i][j]=='O')
{
    A[i][j]='1';
    if(i>0)
    {
        dfs(i-1,j,A);
    }
    if(i+1<A.size())
    {
        dfs(i+1,j,A);
    }
    if(j>0)
    {
        dfs(i,j-1,A);
    }
    if(j+1<A[i].size())
    {
        dfs(i,j+1,A);
    }
}
}

void Solution::solve(vector<vector<char> > &A) {
if(A.size()==0)
return;

int row=A.size();
int col=A[0].size();

//first col and end col
for(int i=0;i<row;i++)
{
dfs(i,0,A);
dfs(i,col-1,A);
}

//first row and end row
for(int i=1;i<col-1;i++)
{
dfs(0,i,A);
dfs(row-1,i,A);
}
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        if(A[i][j]=='1')
        A[i][j]='O';

        else if(A[i][j]=='O')
        A[i][j]='X';
    }
}
}