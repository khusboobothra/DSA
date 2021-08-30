//Problem : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

//Reference : https://www.youtube.com/watch?v=ZqG89Z-dKpI

//Code : Variation of LCS
int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    int lcs[n+1][n+1];
		    for(int i=0;i<=n;i++)
		    {
		        for(int j=0;j<=n;j++)
		        {
		            if(i==0 || j==0)
		            lcs[i][j]=0;
		            
		            else if (str[i-1]==str[j-1] && i!=j)
		            lcs[i][j]=lcs[i-1][j-1]+1;
		            
		            else
		            lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		        }
		    }
		    return lcs[n][n];
		}