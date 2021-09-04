// Problem : https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1

// Code :

int n, m;
    int dx[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
            vector<vector<int>>ans;
            int n=grid.size();
            int m=grid[0].size();
            int len=word.size();

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==word[0])
                    {
                        int x=i,y=j;
                        int k;
                        for(int dir=0;dir<8;dir++)
                        {
                            int xx=x;
                            int yy=y;
                            for(k=0;k<len;k++)
                            {
                                if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==word[k])
                                {
                                     xx=xx+dx[dir];
                                     yy=yy+dy[dir];
                                }

                                else
                                break;  
                            }


                            if(k==len)
                            {
                                ans.push_back({i,j});
                                break;
                            }
                        }
                    }
                    
                }
            }
        if(ans.size()==0)
           ans.push_back({-1});

            return ans;
    }