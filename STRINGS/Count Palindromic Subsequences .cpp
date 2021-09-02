//Problem : https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#

// Reference : https://www.youtube.com/watch?v=vlbA8oUxSV0  [Refer comments for  better understanding]

//Code :
#define mod 1000000007
    int dp[1001][1001];
    long long int func(int i,int j,string &s)
    {
        if(i>j)
        return 0;
        
        if(i==j)
        return 1;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(s[i]==s[j])
        return dp[i][j]=(1 + func(i+1,j,s)%mod + func(i,j-1,s)% mod +mod)%mod;
        
        else
        return dp[i][j]=(func(i+1,j,s)%mod + func(i,j-1,s)%mod - func(i+1,j-1,s)%mod +mod)%mod;
    }
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.length();
       dp[n][n];
       memset(dp,-1,sizeof(dp));
       return func(0,n-1,str)%mod;
    }