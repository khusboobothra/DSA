/* Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the number of cells from where water can flow to both the Blue and Red lake.*/

/* https://www.interviewbit.com/problems/water-flow/*/

//Solution

void dfs(vector<vector<int>>&A,int i,int j,int prev,vector<vector<int> > &ocean)
{
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
//base-cases
if(i<0 || j<0 || i>=ocean.size() || j>=ocean[0].size())
return;
//We will go from the boundaries to the mid. If you see the for loops calling dfs you will observe that we are only calling dfs for the boundries. So, FROM boundaries TO middle of matrix the height will increase. Hence prev should always be less than the current matrix element and the opposite means we reached the end of dfs as the water cannot flow beyond.
// or, the cell is already visited
if(A[i][j]<prev || ocean[i][j]==1)
return;

ocean[i][j]=1;
for(auto d:dir)
{
dfs(A,i+d[0],j+d[1],A[i][j],ocean);
}
}

int Solution::solve(vector<vector<int> > &A) {
    
if(A.size()==0 || A[0].size()==0)
return 0;
int res=0;

int row=A.size();
int col=A[0].size();
vector<vector<int>> blue(row,vector<int>(col,0));
vector<vector<int>> red(row,vector<int>(col,0));

//calling dfs
for(int i=0;i<col;i++)
{
    dfs(A,0,i,INT_MIN,blue);
    dfs(A,row-1,i,INT_MIN,red);
}

for(int i=0;i<row;i++)
{
    dfs(A,i,0,INT_MIN,blue);
    dfs(A,i,col-1,INT_MIN,red);
}
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        if(blue[i][j] && red[i][j])
        res++;
    }
}
return res;
}

