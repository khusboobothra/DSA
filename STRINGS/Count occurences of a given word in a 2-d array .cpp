// Problem : https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1/#

// Reference : https://www.youtube.com/watch?v=ZYeVllg0D7E

// Code :
int solve(int i,int j,vector<vector<char>>mat,string target,int len,int idx)
    {
        int found=0;
        if(i>=0 && i<mat.size() && j>=0 && j<mat[0].size() && mat[i][j]==target[idx])
        {
            char temp=mat[i][j];
            mat[i][j]=0;
            idx+=1;
            
            if(idx==len)
            {
                found=1;
            }
        
            else
            {
            found=found+solve(i+1,j,mat,target,len,idx);
            found=found+solve(i-1,j,mat,target,len,idx);
            found=found+solve(i,j+1,mat,target,len,idx);
            found=found+solve(i,j-1,mat,target,len,idx);  
            }
            //backtarck
            mat[i][j]=temp;
        }
        return found;
    }
    
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        int ans=0;
        int len=target.size();
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                ans=ans+solve(i,j,mat,target,len,0);
            }
        }
        return ans;
}