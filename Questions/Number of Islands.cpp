// Problem : https://leetcode.com/problems/number-of-islands/

//Solution :
void dfs(vector<vector<char>>&grid,int x,int y,int r,int c)
    {
     if(x<0 || x>=r || y<0 || y>=c || grid[x][y]!='1')
     {
         return;
     }
         grid[x][y]='2';
         dfs(grid,x+1,y,r,c);
         dfs(grid,x-1,y,r,c);
         dfs(grid,x,y+1,r,c);
         dfs(grid,x,y-1,r,c);   
     }
    
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
       int r=grid.size();
       int c=grid[0].size();
        if(r==0)
            return 0;
         
        int islands=0;
        for(int i=0;i<r;i++)
        {
           for(int j=0;j<c;j++)
           {    
              if(grid[i][j]=='1')
              {
               dfs(grid,i,j,r,c);
               islands++;
                 
              }
            }
    }
    return islands;
    }