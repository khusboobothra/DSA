//Problem : https://www.interviewbit.com/problems/region-in-binarymatrix/


//Code : 
int cnt;
int x[]={1,1,1,-1,-1,-1,0,0};
int y[]={1,0,-1,1,0,-1,1,-1};
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis)
{
    //current region size increases by 1
    cnt++;
    
    vis[i][j]=true;
    for(int k=0;k<8;k++)//moving in all 8 directions
    {
        int a=i+x[k];
        int b=j+y[k];
        //check if next coordinates are valid and the elements is 1 and not visited before
        if(a>=0&&a<grid.size()&&b>=0&&b<grid[0].size()&&vis[a][b]==false&&grid[a][b]==1)
        {
            dfs(a,b,grid,vis);
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    cnt=0;
    int ans=0;
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //Check if current element is 1 and it has not been visited in a previous encountered region
            if(A[i][j]==1&&vis[i][j]==false)
            {
                cnt=0;
                dfs(i,j,A,vis);
                ans=max(ans,cnt);
            }
        }
    }
    return ans;
}