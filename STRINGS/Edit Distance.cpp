//Problem :

//Code : Use Dynamic Programming

int solve(string s,string t,int m,int n)
{
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            // If first string is empty, only option is to
			// insert all characters of second string
            if(i==0)
            {
                 dp[i][j]=j;
            }
            // If second string is empty, only option is to
			// remove all characters of first string
            else if(j==0)
            {
                dp[i][j]=i;
            }
            //if (i-1)th position of s matches with (j-1)th position of t
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]= 1+min(min(dp[i-1][j] , dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}


int editDistance(string s, string t) {
        // Code here
        int m=s.size();
        int n=t.size();
        return solve(s,t,m,n);
    }