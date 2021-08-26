/*
Problem:
Given N x M character matrix A of O's and X's, where O = white, X = black.
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)


https://www.interviewbit.com/problems/black-shapes/
*/

//Solution
void mark(int i,int j,vector<string>&A,int &count)
{
    A[i][j]='a';

    if(i+1<A.size() && j<A[0].size() && i+1>=0 && j>=0 && A[i+1][j]=='X')
    {
        mark(i+1,j,A,count);
    }
    
    if(i-1<A.size() && j<A[0].size() && i-1>=0 && j>=0 && A[i-1][j]=='X')
    {
        mark(i-1,j,A,count);
    }
    
    if(i<A.size() && j+1<A[0].size() && i>=0 && j+1>=0 && A[i][j+1]=='X')
    {
        mark(i,j+1,A,count);
    }
    
    if(i<A.size() && j-1<A[0].size() && i>=0 && j-1>=0 && A[i][j-1]=='X')
    {
        mark(i,j-1,A,count);
    }
    

}

int Solution::black(vector<string> &A) {
    int count=0;
    int row=A.size();
    int col=A[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j]=='X')
            {
                count++;
                mark(i,j,A,count);
            }
        }
    }
    return count;
}